package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"net/url"
	"os"
	"strconv"
	"strings"
)

// applied on http://www.omdbapi.com
const OMDbURL = "http://www.omdbapi.com/?apikey=b2b8c03"

type ImdbSearchResult struct {
	TotalResults string
	Response     string
	Search       []*Imdb
}

type Imdb struct {
	Title  string
	Year   string
	ImdbID string
	Type   string
	Poster string
}

func Fetch(search string) (*ImdbSearchResult, error) {
	resp, err := http.Get(OMDbURL + "&" + search)
	defer resp.Body.Close()

	if err != nil {
		return nil, err
	}

	if resp.StatusCode != http.StatusOK {
		return nil, fmt.Errorf("Get failed as %s.\n", resp.Status)
	}

	var result ImdbSearchResult
	if err := json.NewDecoder(resp.Body).Decode(&result); err != nil {
		return nil, err
	}

	return &result, nil
}

func AskInput(q string) string {
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Print(q)
		text, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println(err)
			continue
		}
		text = strings.TrimSpace(strings.TrimSuffix(text, "\n"))
		return text
	}
}

func WriteToFile(r io.Reader, file string) {
	f, err := os.Create(file)
	defer f.Close()

	if err != nil {
		err = os.Remove(file)
		f, err = os.Create(file)

		if err != nil {
			fmt.Printf("Failed to remove & create, %s skip.\n", err)
			return
		}
	}

	num := 0
	buf := make([]byte, 256)
	for {
		num, err = r.Read(buf)
		if num == 0 && err == io.EOF {
			return
		}
		f.Write(buf[:num])
	}
}

func DownloadPoster(poster, file string) {
	resp, err := http.Get(poster)
	defer resp.Body.Close()

	if err != nil {
		fmt.Printf("Can not download the poster %v.\n", err)
		return
	}

	if resp.StatusCode != http.StatusOK {
		fmt.Printf("Get %v failed as %s.\n", poster, resp.Status)
		return
	}

	WriteToFile(resp.Body, file)
}

var t = flag.String("title", "", "Title user to search.")

func main() {
	flag.Parse()

	if *t == "" {
		fmt.Printf("Please give search keyword.\n")
		os.Exit(0)
	}

	search := "s=" + url.QueryEscape(*t)

	for {
		result, err := Fetch(search)

		if err != nil {
			log.Fatal(err)
			os.Exit(1)
		}

		if strings.ToLower(result.Response) == "false" {
			fmt.Printf("Can not find any result for given %q.\n", *t)
			os.Exit(0)
		} else {
			fmt.Printf("Got %s results.\n", result.TotalResults)
			total, _ := strconv.Atoi(result.TotalResults)
			number := 0

			for {
				text := AskInput("Pleaes Enter the one you want: ")
				if num, err := strconv.Atoi(text); err != nil {
					fmt.Println(err)
					continue
				} else {
					if num == 0 || num > total {
						fmt.Printf("Size is not valid, should be 1 to %d try again.\n", total)
						continue
					}
					number = num
				}
				break
			}

			// by the default, it's 10 per page
			extra := fmt.Sprintf("&page=%d", ((number-1)/10)+1)
			result, err := Fetch(search + extra)

			if err != nil {
				log.Fatal(err)
				os.Exit(1)
			}

			if strings.ToLower(result.Response) == "false" {
				fmt.Printf("Can not find any result for given %q.\n", search+extra)
				os.Exit(0)
			} else {
				index := (number + 9) % 10

				if len(result.Search) <= index {
					fmt.Printf("Can not find %d result for given %q.\n", number, search+extra)
					os.Exit(0)
				}

				imdb := result.Search[index]
				fmt.Printf("Select %d is \n%#v.\n", number, imdb)

				if imdb.Poster != "N/A" {
					text := AskInput("Do you want to download the Poster: ")
					text = strings.ToLower(text)
					if text == "yes" || text == "y" {
						DownloadPoster(imdb.Poster, fmt.Sprintf("%d.jpg", number))
					}
				}
			}
		}
	}
}
