package main

import (
	"bufio"
	"fmt"
	"os"
)

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	all := make(map[int]map[byte]int)
	for input.Scan() {
		for i, x := range input.Text() {
			if all[i] == nil {
				all[i] = make(map[byte]int)
			}
			all[i][byte(x)]++
		}
	}

	fmt.Println(all)
	var max_ret string
	var min_ret string

	for i := 0; i < len(all); i++ {
		max := 0
		max_c := byte('a')
		min := len(all[0])
		min_c := byte('a')

		for c, num := range all[i] {
			if num > max {
				max_c = c
				max = num
			}
			if num < min {
				min_c = c
				min = num
			}
		}
		max_ret += string(max_c)
		min_ret += string(min_c)
	}

	fmt.Println(max_ret, min_ret)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
