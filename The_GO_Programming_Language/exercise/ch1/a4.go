package main

import (
	"bufio"
	"fmt"
	"os"
)

type Line struct {
	FileName   string
	LineNumber int
}

type Lines []Line

func main() {
	counts := make(map[string]Lines)
	files := os.Args[1:]

	if len(files) == 0 {
		countLines(os.Stdin, counts)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup: %v\n", err)
				continue
			}
			countLines(f, counts)
			f.Close()
		}

		for line, n := range counts {
			if len(n) > 1 {
				fmt.Printf("%s\t%v\n", line, n)
			}
		}
	}
}

func countLines(f *os.File, counts map[string]Lines) {
	input := bufio.NewScanner(f)
	for i := 1; input.Scan(); i++ {
		counts[input.Text()] = append(counts[input.Text()], Line{FileName: f.Name(), LineNumber: i})
	}
}
