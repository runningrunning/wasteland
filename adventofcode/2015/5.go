package main

import (
	"bufio"
	"fmt"
	"os"
)

func naughty1(s string) bool {
	vs := 0
	dup := false
	l := len(s)

	vowel := func(c byte) bool {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
	}

	if vowel(s[0]) {
		vs++
	}

	for i := 1; i < l; i++ {
		if vowel(s[i]) {
			vs++
		}

		if s[i] == s[i-1] {
			dup = true
		}

		if s[i-1:i+1] == "ab" || s[i-1:i+1] == "cd" || s[i-1:i+1] == "pq" || s[i-1:i+1] == "xy" {
			return false
		}
	}

	return dup && vs >= 3
}

func naughty2(s string) bool {
	l := len(s)
	dup, repeat := false, false

	for i := 0; i+1 < l; i += 1 {
		if i != 0 {
			if s[i-1] == s[i+1] {
				repeat = true
			}
		}
		for j := i + 2; j+1 < l; j += 1 {
			if s[i] == s[j] && s[i+1] == s[j+1] {
				dup = true
			}
		}
	}
	return dup && repeat
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)
	sum1, sum2 := 0, 0
	for input.Scan() {
		if naughty1(input.Text()) {
			sum1++
		}
		if naughty2(input.Text()) {
			sum2++
		}
	}

	fmt.Println(sum1, sum2)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
