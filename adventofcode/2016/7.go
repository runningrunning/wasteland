// Better solution????
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func abba(in []string) bool {
	for _, s := range in {
		if len(s) < 4 {
			continue
		}
		for i := 0; i <= len(s)-4; i++ {
			if (s[i] == s[i+3]) && (s[i+1] == s[i+2]) && (s[i] != s[i+1]) {
				return true
			}
		}
	}
	return false
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	sum := 0
	for input.Scan() {
		var in, out []string

		p1 := strings.Split(input.Text(), "[")
		out = append(out, p1[0])
		for _, p := range p1[1:] {
			p2 := strings.Split(p, "]")
			in = append(in, p2[0])
			out = append(out, p2[1])
		}

		if !abba(in) && abba(out) {
			sum++
		}
	}
	fmt.Println(sum)
}

func aba(in []string) (map[string]bool) {
	ret := make(map[string]bool)
	for _, s := range in {
		if len(s) < 3 {
			continue
		}

		for i := 0; i <= len(s) - 3; i ++ {
			if (s[i] == s[i + 2]) && (s[i] != s[i+1]) {
				ret[s[i:i+3]] = true
			}
		}
	}

	return ret
}

func bab(in []string, need map[string]bool) bool {
	for _, s := range in {
		if len(s) < 3 {
			continue
		}

		for i := 0; i <= len(s)-3; i ++ {
			if (s[i] == s[i+2]) && (s[i] != s[i+1]) {
				t := string(s[i+1]) + string(s[i]) + string(s[i + 1])
				if need[t] {
					return true
				}
			}
		}
	}
	return false
}

func q2(f *os.File) {
	input := bufio.NewScanner(f)

	sum := 0

	for input.Scan() {
		var in, out [] string
		p1 := strings.Split(input.Text(), "[")
		out = append(out, p1[0])
		for _, p := range p1[1:] {
			p2 := strings.Split(p, "]")
			in = append(in, p2[0])
			out = append(out, p2[1])
		}

		need := aba(out)

		if bab(in, need) {
			sum ++
		}

	}
	fmt.Println(sum)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
