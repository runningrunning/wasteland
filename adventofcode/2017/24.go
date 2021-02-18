// Simple,  should try leetcode
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func try(ports map[int][]int, cur int, used map[int]bool, score, length int, max, maxl *int) {
	if ports[cur] == nil {
		if length >= *maxl {
			if length > *maxl {
				*max = score
			} else if score > *max {
				*max = score
			}
			*maxl = length
		}
	}

	found := false

	for _, x := range ports[cur] {
		crc := 0
		if cur < x {
			crc = cur*1000 + x
		} else {
			crc = x*1000 + cur
		}
		if !used[crc] {
			found = true
			used[crc] = true
			// fmt.Println("try ", cur, x, score)
			try(ports, x, used, score+cur+x, length + 1, max, maxl)
			used[crc] = false
		}
	}

	if !found {
		if length >= *maxl {
			if length > *maxl {
				*max = score
			} else if score > *max {
				*max = score
			}
			*maxl = length
		}
	}
}


func q1(f *os.File) {
	input := bufio.NewScanner(f)
	ports := make(map[int][]int)
	for input.Scan() {
		lines := strings.Split(input.Text(), "/")
		x, _ := strconv.Atoi(lines[0])
		y, _ := strconv.Atoi(lines[1])
		ports[x] = append(ports[x], y)
		ports[y] = append(ports[y], x)
	}
	fmt.Println(ports)

	max := 0
	maxl := 0
	cur := 0
	used := make(map[int]bool)

	try(ports, cur, used, 0, 0, &max, &maxl)
	fmt.Println(max)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
