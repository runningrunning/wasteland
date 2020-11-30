package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var overall, invalid int = 0, 0

func main() {
	counts := make(map[string]int)

	files := os.Args[1:]

	if len(files) == 0 {
		countWords(os.Stdin, counts)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "countWorlds: %v.\n", err)
				continue
			}
			countWords(f, counts)
			f.Close()
		}
	}
	nums := make(map[int][]string)
	for w, n := range counts {
		// fmt.Printf("%s\t%d\n", w, n)
		if nums[n] == nil {
			nums[n] = []string{}
		}
		nums[n] = append(nums[n], w)
	}

	ns := []int{}
	for n, ws := range nums {
		ns = append(ns, n)
		sort.Strings(ws)
	}
	sort.Ints(ns)
	for _, i := range ns {
		fmt.Printf("%d:%v\n", i, nums[i])
	}
}

func countWords(f *os.File, counts map[string]int) {
	input := bufio.NewScanner(f)
	input.Split(bufio.ScanWords)
	for input.Scan() {
		counts[input.Text()]++
	}
}
