package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func q1(f *os.File, last bool) {
	rs := make(map[string]int)
	max := 0
	input := bufio.NewScanner(f)
	for input.Scan() {
		ps := strings.Split(input.Text(), " ")
		if ps[3] != "if" {
			fmt.Println("Condition failed. Exit")
			os.Exit(0)
		}
		value, _ := strconv.Atoi(ps[2])
		if ps[1] == "dec" {
			value = -value
		}
		ovalue, _ := strconv.Atoi(ps[6])
		switch ps[5] {
		case ">":
			if rs[ps[4]] > ovalue {
				rs[ps[0]] += value
			}
		case "<":
			if rs[ps[4]] < ovalue {
				rs[ps[0]] += value
			}
		case ">=":
			if rs[ps[4]] >= ovalue {
				rs[ps[0]] += value
			}
		case "<=":
			if rs[ps[4]] <= ovalue {
				rs[ps[0]] += value
			}
		case "==":
			if rs[ps[4]] == ovalue {
				rs[ps[0]] += value
			}
		case "!=":
			if rs[ps[4]] != ovalue {
				rs[ps[0]] += value
			}
		}

		if rs[ps[0]] > max {
			max = rs[ps[0]]
		}
	}

	if last {
		max = 0
		for _, v := range rs {
			if v > max {
				max = v
			}
		}
	}

	fmt.Println(max)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f, true)
	f.Seek(0, 0)
	q1(f, false)
}
