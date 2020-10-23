package main

import (
	"fmt"
	"unicode/utf8"
)

func anagram(a, b string) bool {
	if len(a) != len(b) {
		return false
	}

	if a == b {
		return true
	}

	var al = utf8.RuneCountInString(a)
	var bl = utf8.RuneCountInString(b)

	if al != bl {
		return false
	}

	var as = map[rune]int{}
	var bs = map[rune]int{}

	for i := 0; i < len(a); {
		r, size := utf8.DecodeRuneInString(a[i:])
		as[r]++
		i += size
	}

	for i := 0; i < len(b); {
		r, size := utf8.DecodeRuneInString(b[i:])
		bs[r]++
		i += size
	}

	if len(as) != len(bs) {
		return false
	}

	for k, _ := range as {
		if as[k] != bs[k] {
			return false
		}
	}
	return true
}

func main() {
	a := "abc"
	b := "cba"
	fmt.Printf("%v == %v is %v.\n", a, b, anagram(a, b))
	a = "abc世界你好/+"
	b = "你好界世bca+/"
	fmt.Printf("%v == %v is %v.\n", a, b, anagram(a, b))
	s1 := "界世"
	s2 := "\xe4\xb8\x96\xe7\x95\x8c"
	s3 := "\u754c\xE4\xB8\x96"
	s4 := "\U00004e16\U0000754c"
	fmt.Printf("%v == %v is %v.\n", s2, s3, anagram(s3, s2))
	fmt.Printf("%v == %v is %v.\n", s1, s4, anagram(s1, s4))
	fmt.Printf("%v == %v is %v.\n", s1, s3, anagram(s1, s3))
}
