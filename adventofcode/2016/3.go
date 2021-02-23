// Think too complex
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func valid(i []int) bool {
	return ((i[0]+i[1] > i[2]) && (i[0]+i[2] > i[1]) && (i[1]+i[2] > i[0]))
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	sum := 0
	t := [3]int{}

	for input.Scan() {
		i := 0
		for _, x := range strings.Split(strings.TrimSpace(input.Text()), " ") {
			if len(x) != 0 {
				z, _ := strconv.Atoi(x)
				t[i] = z
				i++
			}
		}
		if valid(t[0:]) {
			sum++
		}
	}

	fmt.Println(sum)
}

func _max(i, c []int, x int) int {
	if x + 3 > len(i) {
		return 0
	}

	if c[x] != 0 {
		return c[x]
	}

	with := 0

	if valid(i[x:]) {
		with = 1 + _max(i, c, x + 3)
	}

	without := _max(i, c, x + 1)

	if with > without {
		c[x] = with
	} else {
		c[x] = without
	}
	return c[x]
}

func max(i []int) int {
	return _max(i, make([]int, len(i), len(i)), 0)
}

func q2(f *os.File) {
	input := bufio.NewScanner(f)
	sum := 0

	all := [3][]int{}

	for input.Scan() {
		i := 0
		for _, x := range strings.Split(input.Text(), " ") {
			if len(x) != 0 {
				t, _ := strconv.Atoi(x)
				all[i] = append(all[i], t)
				i++
			}
		}
	}

	for _, line := range all {
		sum += max(line)
	}

	fmt.Println(sum)
}

func q2_1(f *os.File) {
	input := bufio.NewScanner(f)
	sum := 0

	all := [3][]int{}

	for input.Scan() {
		i := 0
		for _, x := range strings.Split(input.Text(), " ") {
			if len(x) != 0 {
				t, _ := strconv.Atoi(x)
				all[i] = append(all[i], t)
				i++
			}
		}
	}

	for _, line := range all {
		for i := 0; i + 2 < len(line); i += 3 {
			if valid(line[i:]) {
				sum ++
			}
		}
	}

	fmt.Println(sum)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Seek(0, 0)
	q2_1(f)
}
