package main

import (
	"fmt"
	"unicode/utf8"
)

func reverse(s []byte) []byte {
	for i, j := 0, len(s)-1; j > i; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func reverseUTF8(s []byte) []byte {
	i := 0
	for {
		r, n := utf8.DecodeRune(s[i:])
		if r == utf8.RuneError {
			fmt.Printf("%v %v.\n", r, n)
			break
		}
		fmt.Printf("%v:%v %v\n", n, s[i:i+n], string(s[i:i+n]))
		reverse(s[i:i+n])
		i += n
	}
	reverse(s)
	return s
}

func printfEach(s string) {
	for _, r := range s {
		fmt.Printf("'%c' ", r)
	}
	fmt.Printf("\n")
}

func main() {
	// fmt output error, contain \v\f
	// s := []byte("Hello, \t\n\v\f \r this     \u00a0新 世 界 ")
	s := []byte("Hello, \t\n\r\v\f this \u0085     \u00a0新 世 界 \v\fthis")
	fmt.Println(string(s))
	fmt.Println(s)
	printfEach(string(s))
	fmt.Println(string(reverseUTF8(s)))
	fmt.Println(s)
	printfEach(string(s))
	fmt.Println(string(reverseUTF8(s)))
}

