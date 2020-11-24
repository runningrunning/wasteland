package main

import (
	"fmt"
	"unicode"
	"unicode/utf8"
)

func removeDupSpace(s []byte) []byte {
	i, j := 0, 0
	previousSpace := false

	for {
		r, n := utf8.DecodeRune(s[i:])
		if unicode.IsSpace(r) {
			previousSpace = true
		} else {
			if previousSpace {
				s[j] = ' '
				j += 1
			}
			previousSpace = false

			if r == utf8.RuneError {
				return s[:j]
			}
			copy(s[j:j+n], s[i:i+n])
			j += n
		}
		i += n
	}
	return s
}

func main() {
	s := []byte("Hello, \t\n\v\f\r this     \u00a0新 世 界 ")
	fmt.Println(string(s))
	fmt.Println(string(removeDupSpace(s)))
}
