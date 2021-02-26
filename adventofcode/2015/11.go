package main

import (
	"fmt"
)

var i2c map[int]byte
var c2i = map[byte]int{'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'j': 8, 'k': 9, 'm': 10, 'n': 11, 'p': 12, 'q': 13, 'r': 14, 's': 15, 't': 16, 'u': 17, 'v': 18, 'w': 19, 'x': 20, 'y': 21, 'z': 22}
var bits = len(c2i)


func toPassword(n int) (p string) {
	for i := 0; i < 8; i++ {
		p = string(i2c[n%bits]) + p
		n /= bits
	}
	return p
}

func toInt(s string) (r int) {
	b := 1

	for i := len(s) - 1; i >= 0; i-- {
		r += b * c2i[s[i]]
		b *= bits
	}

	return
}

func valid(s string) bool {
	pairs := 0
	triple := 0

	for i := 0; i < len(s)-2; i++ {
		if s[i]+1 == s[i+1] && s[i+1]+1 == s[i+2] {
			triple = 1
		}
	}

	if triple == 0 {
		return false
	}

	for i := 0; i < len(s)-1; i++ {
		if s[i] == s[i+1] {
			pairs += 1
			i += 1
		}
	}

	return pairs > 1
}

func q1(s string) {
	i := toInt(s) + 1

	for !valid(toPassword(i)) {
		i++
	}
	fmt.Println(toPassword(i))
}

func main() {
	i2c = make(map[int]byte)
	for c, i := range c2i {
		i2c[i] = c
	}
	fmt.Println(toPassword(toInt("abcdefgh")))
	fmt.Println(toPassword(toInt("abcdefgh")+1))
	q1("hepxcrrq")
	q1("hepxxyzz")
}
