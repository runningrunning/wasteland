package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func parser(f *os.File) (string, map[string][]string, map[string]int) {
	input := bufio.NewScanner(f)
	trees := make(map[string][]string)
	values := make(map[string]int)
	internal := make(map[string]bool)

	for input.Scan() {
		sep := strings.Split(input.Text(), "->")
		line := strings.Split(strings.TrimSpace(sep[0]), " ")
		disk, _ := strconv.Atoi(line[1][1 : len(line[1])-1])

		values[line[0]] = disk

		if len(sep) > 1 {
			sep[1] = strings.TrimSpace(sep[1])
			trees[line[0]] = strings.Split(sep[1], ", ")

			for _, s := range trees[line[0]] {
				internal[s] = true
			}
		}
	}

	var root string

	for n, _ := range values {
		if !internal[n] {
			root = n
			break
		}
	}

	return root, trees, values
}

func update(r string, t map[string][]string, v, ov map[string]int) (int, int) {
	if t[r] == nil {
		return v[r], 0
	}

	failed := 0
	subs := make(map[int]int)

	for _, s := range t[r] {
		sub, wrong := update(s, t, v, ov)
		subs[sub] += 1
		if wrong != 0 {
			failed = wrong
		}
		v[r] += sub
	}

	if failed != 0 || len(subs) == 1 {
		return v[r], failed
	}

	correct, wrong := 0, 0

	for v, n := range subs {
		if n != 1 {
			correct = v
		} else {
			wrong = v
		}
	}

	for _, s := range t[r] {
		if v[s] == wrong {
			ov[s] = ov[s] + correct - wrong
			if ov[s] < 0 {
				fmt.Println("Some thing wrong here", ov[s])
			}
			failed = ov[s]
			break
		}
	}

	return v[r], failed
}

func q1(f *os.File) {
	r, _, _ := parser(f)
	fmt.Println(r)
}

func q2(f *os.File) {
	r, t, v := parser(f)
	ov := make(map[string]int)
	for s, i := range v {
		ov[s] = i
	}
	fmt.Println(update(r, t, v, ov))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
