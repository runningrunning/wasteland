// strings.TrimSpace will remove all of whitespace leading and trailing (include line break '\n' at the last)
package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func next(bank []int) []int {
	max := 0
	nx := make([]int, len(bank))
	for i, n := range bank {
		nx[i] = n
		if n > bank[max] {
			max = i
		}
	}

	left := nx[max]
	nx[max] = 0
	max += 1

	for left != 0 {
		nx[max % len(bank)] += 1
		max += 1
		left -= 1
	}
	return nx
}

func equal(a, b []int) bool {
	for i, _ := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func q1(f *os.File) {
	var banks []int
	raw, _ := ioutil.ReadAll(f)
	fmt.Println(string(raw))
	input := strings.TrimSpace(string(raw))
	fmt.Println(input)

	for _, s := range strings.Split(input, "\t") {
		x, _ := strconv.Atoi(s)
		banks = append(banks, x)
	}
	fmt.Println(banks)

	steps := 0
	var history [][]int
	history = append(history, banks)

	for {
		banks = next(banks)
		steps += 1

		for i, h := range history {
			if equal(h, banks) {
				fmt.Println(steps - i)
				return
			}
		}
		history = append(history, banks)
	}
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
}
