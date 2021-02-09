// handle infinite matching
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Token struct {
	Value string
	Cond  [][]int
}

type Rules map[int]Token

// used to speed up
type Cache map[int]map[string]bool

var cache Cache
var rules Rules

func parser(line string) {
	items := strings.Split(line, ":")
	id, _ := strconv.Atoi(items[0])
	rs := strings.Split(items[1], "|")

	t := Token{}

	for _, r := range rs {
		r = strings.TrimSpace(r)
		if r[0] == '"' {
			t.Value = r[1 : len(r)-1]
		} else {
			ts := strings.Split(r, " ")
			its := make([]int, len(ts))
			for i := 0; i < len(ts); i++ {
				its[i], _ = strconv.Atoi(ts[i])
			}
			t.Cond = append(t.Cond, its)
		}
	}
	rules[id] = t
	cache[id] = make(map[string]bool)
}

func match_Token(s string, t int) (bool, bool) {
	if match, ok := cache[t][s]; ok {
		return match, true
	}

	token := rules[t]

	if token.Cond != nil {
		for _, cs := range token.Cond {
			if match_Rule(s, cs) {
				cache[t][s] = true
				return true, true
			}
		}
	}

	if token.Value != "" {
		if s == token.Value {
			cache[t][s] = true
			return true, false
		}
		cache[t][s] = false
		return false, len(s) <= len(token.Value)
	}
	cache[t][s] = false

	// should we keep it as true to contiue ?
	return false, true
}

func match_Rule(s string, c []int) bool {
	if len(c) == 0 {
		return len(s) == 0
	}

	if len(s) == 0 {
		return false
	}

	for i := 0; i < len(s); i++ {
		m, k := match_Token(s[:i+1], c[0])

		if m && match_Rule(s[i+1:], c[1:]) {
			return true
		}

		if !k {
			break
		}
	}
	return false
}

func match(s string) bool {
	m, _ := match_Token(s, 0)
	return m
}

func q1(f *os.File) {
	sum := 0
	parsing := true
	input := bufio.NewScanner(f)
	for input.Scan() {
		if len(input.Text()) == 0 {
			parsing = false
			continue
		}
		if parsing {
			parser(input.Text())
		} else {
			if match(input.Text()) {
				sum++
			}
		}
	}
	fmt.Println(sum)
}

func main() {
	cache = make(Cache)
	rules = make(Rules)
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
