package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func re(s string) string {
	cs := make([]int, 26)
	for _, c := range s {
		cs[int(c-'a')] += 1
	}
	bi := 0
	bs := make([]byte, len(s))
	for i, n := range cs {
		for j := 0; j < n; j++ {
			bs[bi] = byte('a' + i)
			bi += 1
		}
	}
	return string(bs)
}

func q1(f *os.File, rearrange bool) {
	sum := 0
	input := bufio.NewScanner(f)
	for input.Scan() {
		valid := true
		passphrase := make(map[string]bool)
		for _, p := range strings.Split(input.Text(), " ") {
			if rearrange {
				p = re(p)
			}

			if passphrase[p] {
				valid = false
				break
			}

			passphrase[p] = true
		}

		if valid {
			sum++
		}
	}
	fmt.Println(sum)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f, false)
	f.Seek(0, 0)
	q1(f, true)
}
