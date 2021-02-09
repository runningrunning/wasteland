package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	var all []int
	for input.Scan() {
		if len(input.Text()) == 0 {
			break
		}

		x, _ := strconv.Atoi(input.Text())
		all = append(all, x)
	}
	sort.Ints(all)

	n1 := 0
	n3 := 1
	p := 0

	for _, x := range all {
		if x-p == 1 {
			n1++
		}

		if x-p == 3 {
			n3++
		}
		p = x
	}

	fmt.Println(n1, n3)
}

// count the same number?
func q2(f *os.File) {
	input := bufio.NewScanner(f)

	var all []int

	for input.Scan() {
		if len(input.Text()) == 0 {
			break
		}

		x, _ := strconv.Atoi(input.Text())
		all = append(all, x)
	}
	sort.Ints(all)
	nums := make([]int, len(all))

	for i := len(all) - 1; i >= 0; i-- {
		if i == len(all)-1 {
			nums[i] = 1
		} else {
			for j := i + 1; j < len(all) && all[j] <= all[i]+3; j++ {
				nums[i] += nums[j]
			}
		}
	}

	total := 0
	for i := 0; i < len(all); i++ {
		if all[i] < 4 {
			total += nums[i]
		}
	}

	fmt.Println(total)
}

func main() {
	f, _ := os.Open(os.Args[1])
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Close()
}
