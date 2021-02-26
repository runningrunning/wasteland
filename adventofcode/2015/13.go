// can add both people A->B and B->A into one score, then it's B-A or A-B undirect graph
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func parse(f *os.File) (map[string]map[string]int, map[string]bool) {
	f.Seek(0, 0)
	input := bufio.NewScanner(f)
	happiness := make(map[string]map[string]int)
	people := make(map[string]bool)

	for input.Scan() {
		t := input.Text()
		// remove the last .
		ws := strings.Split(t[:len(t)-1], " ")
		h, _ := strconv.Atoi(ws[3])
		if ws[2] == "lose" {
			h = -h
		}
		if happiness[ws[0]] == nil {
			happiness[ws[0]] = make(map[string]int)
		}
		happiness[ws[0]][ws[10]] = h
		people[ws[0]] = true
		people[ws[10]] = true
	}
	return happiness, people
}

func max_happy(hs map[string]map[string]int, ps map[string]bool, cur, first string, num, happy int, used map[string]bool, min *int) {
	if num == len(ps) {
		if happy+hs[cur][first]+hs[first][cur] > *min {
			*min = happy + hs[cur][first] + hs[first][cur]
		}
	} else {
		for p, _ := range ps {
			if used[p] {
				continue
			}

			used[p] = true
			max_happy(hs, ps, p, first, num+1, happy+hs[cur][p]+hs[p][cur], used, min)
			used[p] = false
		}
	}
}

func q1(f *os.File) {
	hs, ps := parse(f)

	used := make(map[string]bool)
	min := 0

	for p, _ := range ps {
		used[p] = true
		max_happy(hs, ps, p, p, 1, 0, used, &min)
		used[p] = false
	}
	fmt.Println(min)
}

func q2(f *os.File) {
	hs, ps := parse(f)
	used := make(map[string]bool)
	min := 0

	// fake me

	hs["ME"] = make(map[string]int)
	for p, _ := range ps {
		hs["ME"][p] = 0
		hs[p]["ME"] = 0
	}
	ps["ME"] = true

	for p, _ := range ps {
		used[p] = true
		max_happy(hs, ps, p, p, 1, 0, used, &min)
		used[p] = false
	}
	fmt.Println(min)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	q2(f)
}
