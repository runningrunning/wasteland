package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func mark(pros map[int][]int, p int, m map[int]bool) {
	if m[p] {
		return
	}
	m[p] = true
	for _, t := range pros[p] {
		mark(pros, t, m)
	}
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)
	pros := make(map[int][]int)
	groups := make(map[int]int)

	for input.Scan() {
		ps := strings.Split(input.Text(), " <-> ")
		from, _ := strconv.Atoi(ps[0])
		var to []int
		for _, x := range strings.Split(ps[1], ", ") {
			t, _ := strconv.Atoi(x)
			to = append(to, t)
		}
		pros[from] = append(pros[from], to...)

	}

	marks := make(map[int]bool)

	for len(marks) != len(pros) {
		s := 0
		ol := len(marks)
		if ol != 0 {
			for k, _ := range pros {
				if marks[k] == false {
					s = k
					break
				}
			}
		}

		for _, t := range pros[s] {
			mark(pros, t, marks)
		}
		groups[s] = len(marks) - ol
	}

	fmt.Println(groups[0], len(groups))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
