// Read it carefully, it's undirected graph !
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func short(d map[string]map[string]int, loc, used map[string]bool, cur string, p, n int, min, max *int) {
	if n == len(loc) {
		if p < *min {
			*min = p
		}
		if p > *max {
			*max = p
		}
		return
	}

	for nxt, ds := range d[cur] {
		if used[nxt] {
			continue
		}
		used[nxt] = true
		short(d, loc, used, nxt, p+ds, n+1, min, max)
		used[nxt] = false
	}
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	dis := make(map[string]map[string]int)
	loc := make(map[string]bool)

	for input.Scan() {
		ws := strings.Split(input.Text(), " ")
		num, _ := strconv.Atoi(ws[4])
		if dis[ws[0]] == nil {
			dis[ws[0]] = make(map[string]int)
		}
		if dis[ws[2]] == nil {
			dis[ws[2]] = make(map[string]int)
		}
		loc[ws[0]] = true
		loc[ws[2]] = true
		dis[ws[0]][ws[2]] = num
		dis[ws[2]][ws[0]] = num
	}

	min := int((^uint(0)) >> 1)
	max := 0
	used := make(map[string]bool)

	for c, _ := range loc {
		used[c] = true
		short(dis, loc, used, c, 0, 1, &min, &max)
		used[c] = false
	}

	fmt.Println(min, max)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
