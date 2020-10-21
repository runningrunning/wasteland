package main

import (
	"bytes"
	"fmt"
)

func comma(s string) string {
	l := len(s)

	if l <= 3 {
		return s
	}

	var i int
	var buf bytes.Buffer

	for i = 0; i < l%3; i++ {
		buf.WriteByte(s[i])
	}

	for j := 0; j < l/3; j++ {
		if i != 0 {
			buf.WriteByte(',')
		}
		buf.WriteByte(s[i])
		buf.WriteByte(s[i+1])
		buf.WriteByte(s[i+2])
		i += 3
	}

	return buf.String()
}

func main() {
	s := "123"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "1234"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "123456789"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "12345678910"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "1234567890"
	fmt.Printf("%s => %s\n", s, comma(s))
}
