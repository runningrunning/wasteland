package main

import (
	"fmt"
	"os"
	"tgpl/fetch"
)

func main() {
	for _, url := range os.Args[1:] {
		resp, err := fetch.FetchStr(url)

		if err != nil {
			os.Exit(1)
		}

		fmt.Printf("%s", resp)
	}
}
