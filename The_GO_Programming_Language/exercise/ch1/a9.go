package main

import (
	"os"
	"tgpl/fetch"
)

func main() {
	for _, url := range os.Args[1:] {
		if err := fetch.FetchIOWithStatus(url, os.Stdout); err != nil {
			os.Exit(1)
		}
	}
}
