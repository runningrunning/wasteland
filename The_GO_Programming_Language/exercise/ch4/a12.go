package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"strconv"
	"strings"
)

const XkcdURL = "https://xkcd.com/%d/info.0.json"

type Comic struct {
	Month      string
	Num        int
	Link       string
	Year       string
	News       string
	SafeTitle  string `json:"safe_title"`
	Transcript string
	Alt        string
	Img        string
	Title      string
	Day        string
}

func FetchAll() map[int]*Comic {
	start, error := 1, 0

	all := map[int]*Comic{}
	for {
		resp, err := http.Get(fmt.Sprintf(XkcdURL, start))

		if err != nil {
			log.Fatal(err)
		}

		if resp.StatusCode != http.StatusOK {
			error++
			if error > 10 {
				resp.Body.Close()
				break
			}
			fmt.Errorf("search query failed: %s", resp.Status)
		} else {
			var c Comic
			if err := json.NewDecoder(resp.Body).Decode(&c); err != nil {
				log.Fatal(err)
			} else {
				error = 0
				all[c.Num] = &c
			}
		}
		resp.Body.Close()
		start++
	}
	return all
}

const local = "a12.json"

var k = flag.String("keyword", "", "Keyword used in Transcript.")
var n = flag.String("number", "", "Pick XKCD for this Number.")
var y = flag.String("year", "", "List XKCD for this year.")

func main() {
	flag.Parse()

	var data []byte
	var err error
	var all map[int]*Comic

	if data, err = ioutil.ReadFile(local); err != nil {
		all = FetchAll()
		data, err = json.Marshal(all)
		if err != nil {
			log.Fatalf("JSON Marshaling failed: %s", err)
		}
		if err = ioutil.WriteFile(local, data, 0777); err != nil {
			log.Fatalf("Write File failed: %s", err)
		}
	} else {
		if err = json.Unmarshal(data, &all); err != nil {
			log.Fatalf("JSON Unmarshaling failed: %s", err)
		}
	}

	// nil slice
	var result []*Comic
	num := 0

	if *n != "" {
		if num, err = strconv.Atoi(*n); err != nil {
			log.Fatalf("Input number is invalid: %s", err)
		} else if all[num] != nil {
			if (*y == "" || all[num].Year == *y) && (*k == "" || strings.Contains(all[num].Transcript, *k)) {
				result = append(result, all[num])
			}
		}
	} else if *y != "" || *k != "" {
		for _, r := range all {
			if (*y == "" || r.Year == *y) && (*k == "" || strings.Contains(r.Transcript, *k)) {
				result = append(result, r)
			}
		}
	} else {
		fmt.Println("Must specific search condition.")
	}

	if len(result) != 0 {
		if len(result) == 1 {
			fmt.Printf("Found 1 match.\n")
		} else {
			fmt.Printf("Fount %d matches.\n", len(result))
		}

		for _, r := range result {
			fmt.Printf("%#v\n", r)
		}

	} else {
		fmt.Println("Can not find any matches.")
	}
}
