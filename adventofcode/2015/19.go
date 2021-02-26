package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"sort"
)

func parse(f *os.File) (re map[string][]string, me string) {
	f.Seek(0, 0)
	re = make(map[string][]string)
	input := bufio.NewScanner(f)
	for input.Scan() {
		if len(input.Text()) == 0 {
			continue
		}

		if strings.Contains(input.Text(), "=>") {
			ws := strings.Split(input.Text(), "=>")
			key := strings.TrimSpace(ws[0])
			re[key] = append(re[key], strings.TrimSpace(ws[1]))
		} else {
			me = strings.TrimSpace(input.Text())
		}
	}
	return
}

func once(re map[string][]string, me string, hash map[string]bool) {
	for i := 0; i < len(me); i++ {
		for k, v := range re {
			if strings.HasPrefix(me[i:], k) {
				for _, r := range v {
					hash[me[:i]+r+me[i+len(k):]] = true
				}
			}
		}
	}
}

func q1(f *os.File) int {
	re, me := parse(f)
	hash := make(map[string]bool)
	once(re, me, hash)
	return len(hash)
}

// greedy and rever to the result
// func q2(f *os.File) int {
// 	re, me := parse(f)
// 	seen := make(map[string]bool)
// 	a := make(map[string]bool)
// 	a["e"] = true

// 	step := 0
// 	for {
// 		b := make(map[string]bool)
// 		fmt.Println(step, len(a))
// 		for m, _ := range a {
// 			if seen[m] {
// 				continue
// 			}

// 			if me == m {
// 				return step
// 			}

// 			seen[m] = true
// 			once(re, m, b)
// 		}
// 		a = b
// 		step ++
// 	}

// 	return -1
// }

// greedy and rever to the result
func q2(f *os.File) int {
	re, me := parse(f)
	rre := make(map[string]string)
	var rk []string

	for k, v := range re {
		for _, r := range v {
			rre[r] = k
			rk = append(rk, r)
		}
	}
	step := 0
	sort.Slice(rk, func(i, j int) bool { return len(rk[i]) >= len(rk[j]) })

	cur := me

	for {
		for _, k := range rk {
			for i := 0; i < len(cur); i++ {
				if strings.HasPrefix(cur[i:], k) {
					cur = cur[:i] + rre[k] + cur[i+len(k):]
					i += len(rre[k]) - 1
					step += 1
				}
			}
		}
		if cur == "e" {
			break
		}
		// fmt.Println(cur, step)
	}
	return step
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	fmt.Println(q1(f))
	fmt.Println(q2(f))
}
