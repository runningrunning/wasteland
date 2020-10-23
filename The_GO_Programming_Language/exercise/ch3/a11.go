package main

import (
	"bytes"
	"fmt"
	"strings"
)

func do_comma(s string, decimal bool) string {
	var i int
	var buf bytes.Buffer
	if decimal {
		for i = 0; i < len(s); i++ {
			if i != 0 && (i%3) == 0 {
				buf.WriteByte(',')
			}
			buf.WriteByte(s[i])
		}
	} else {
		if s[0] == '+' || s[0] == '-' {
			buf.WriteByte(s[0])
			s = s[1:]
		}

		l := len(s)

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
	}

	return buf.String()
}

func comma(s string) string {
	dot := -1
	if dot = strings.LastIndex(s, "."); dot == -1 {
		return do_comma(s, false)
	}

	return do_comma(s[:dot], false) + "." + do_comma(s[dot+1:], true)
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
	s = "1.234"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "12.3456789"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "12345.678910"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "12345678.90"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "-012.3456789"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "+120345.678910"
	fmt.Printf("%s => %s\n", s, comma(s))
	s = "12345678.908989893"
	fmt.Printf("%s => %s\n", s, comma(s))
}
