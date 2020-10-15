/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
	"os"
	"tgpl/fetch"
)

func main() {
	for _, url := range os.Args[1:] {
		if err := fetch.FetchIO(url, os.Stdout); err != nil {
			os.Exit(1)
		}
	}
}
