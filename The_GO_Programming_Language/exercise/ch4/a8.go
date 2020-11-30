package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"unicode"
	"unicode/utf8"
)

var invalid int = 0
var overall int = 0

func charCount(in *bufio.Reader, counts map[string]int, utflen []int) {
	for {
		r, n, err := in.ReadRune()

		if err == io.EOF {
			break
		}

		if err != nil {
			fmt.Fprintf(os.Stderr, "charcount: %v\n", err)
			os.Exit(1)
		}

		if r == unicode.ReplacementChar && n == 1 {
			invalid++
			continue
		}

		for t, c := range unicode.Categories {
			if unicode.Is(c, r) {
				counts[t]++
			}
		}
		utflen[n]++
		overall++
	}
}

func main() {
	counts := make(map[string]int)
	var utflen [utf8.UTFMax + 1]int

	if len(os.Args) > 1 {
		for _, arg := range os.Args[1:] {
			f, err := os.Open(arg)

			if err != nil {
				fmt.Fprintf(os.Stderr, "Can not open %v.\n", err)
			}
			charCount(bufio.NewReader(f), counts, utflen[:])
			f.Close()
		}
	} else {
		charCount(bufio.NewReader(os.Stdin), counts, utflen[:])
	}

	fmt.Printf("Category\tcount\n")
	for c, n := range counts {
		fmt.Printf("%q\t%d\n", c, n)
	}

	fmt.Printf("\nlen\tcount\n")
	for i, n := range utflen {
		if i > 0 {
			fmt.Printf("%d\t%d\n", i, n)
		}
	}

	fmt.Printf("\nOverall %d, invalid %d.\n", overall, invalid)
}
