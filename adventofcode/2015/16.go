package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func parse(f *os.File) (all []map[string]int) {
	f.Seek(0, 0)
	input := bufio.NewScanner(f)
	toInt := func(s string) int {
		if s[len(s)-1] == ',' || s[len(s)-1] == ':' {
			s = s[:len(s)-1]
		}
		n, _ := strconv.Atoi(s)
		return n
	}

	for input.Scan() {
		ws := strings.Split(input.Text(), " ")
		c := make(map[string]int)
		c[ws[0]] = toInt(ws[1])
		c[ws[2]] = toInt(ws[3])
		c[ws[4]] = toInt(ws[5])
		c[ws[6]] = toInt(ws[7])
		all = append(all, c)
	}

	return
}

func q1(f *os.File) {
	all := parse(f)

	sample := map[string]int{
		"children:":    3,
		"cats:":        7,
		"samoyeds:":    2,
		"pomeranians:": 3,
		"akitas:":      0,
		"vizslas:":     0,
		"goldfish:":    5,
		"trees:":       3,
		"cars:":        2,
		"perfumes:":    1,
	}

	for _, c := range all {
		match := true
		for k, v := range c {
			if k == "Sue" {
				continue
			}
			if sample[k] != v {
				match = false
			}
		}

		if match {
			fmt.Println(c)
		}
	}
}

func q2(f *os.File) {
	all := parse(f)

	sample := map[string]int{
		"children:":    3,
		"cats:":        7,
		"samoyeds:":    2,
		"pomeranians:": 3,
		"akitas:":      0,
		"vizslas:":     0,
		"goldfish:":    5,
		"trees:":       3,
		"cars:":        2,
		"perfumes:":    1,
	}

	for _, c := range all {
		match := true
		for k, v := range c {
			if k == "Sue" {
				continue
			}

			if k == "cats:" || k == "trees:" {
				if sample[k] >= v {
					match = false
				}
			} else if k == "pomeranians:" || k == "goldfish:" {
				if sample[k] <= v {
					match = false
				}
			} else if sample[k] != v {
				match = false
			}
		}

		if match {
			fmt.Println(c)
		}
	}
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	q2(f)
}
