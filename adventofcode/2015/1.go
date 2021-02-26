package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func q1(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))

	base := 0
	fl := 0
	for i, c := range input {
		if c == ')' {
			fl--
		} else {
			fl++
		}
		if fl == -1 {
			if base == 0 {
				base = i + 1
			}
		}
	}

	fmt.Println(fl, base)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
