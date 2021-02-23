// simpler than segment tree?
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func q1(f *os.File, max int) int {
	var starts []int
	ends := make(map[int]int)
	ends[max + 1] = max + 1
	starts = append(starts, max + 1)
	input := bufio.NewScanner(f)
	for input.Scan() {
		var low, high int
		fmt.Sscanf(input.Text(), "%d-%d", &low, &high)
		if ends[low] < high {
			if ends[low] == 0 {
				starts = append(starts, low)
			}
			ends[low] = high
		}
	}
	sort.Ints(starts)


	ip := 0
	nums := 0
	first := 0
	for i := 0; i < len(starts); i++ {
		if ip < starts[i] {
			if first == 0 {
				first = ip
			}
			nums += starts[i] - ip
		}
		if ip < ends[starts[i]] + 1 {
			ip = ends[starts[i]] + 1
		}
	}
	fmt.Println("num is", nums)
	return first
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	fmt.Println(q1(f, 4294967295))
}
