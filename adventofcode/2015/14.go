// Be careful
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func parse(f *os.File) (all [][]int) {
	f.Seek(0, 0)
	input := bufio.NewScanner(f)

	toInt := func(s string) int {
		n, _ := strconv.Atoi(s)
		return n
	}

	for input.Scan() {
		ws := strings.Split(input.Text(), " ")
		var c []int
		c = append(c, toInt(ws[3]))
		c = append(c, toInt(ws[6]))
		c = append(c, toInt(ws[13]))
		all = append(all, c)
	}
	return
}

func q1(f *os.File, t int) {
	max := 0
	all := parse(f)
	for _, c := range all {
		turns := t / (c[1] + c[2])
		left := t % (c[1] + c[2])
		if left > c[1] {
			left = c[1]
		}
		dis := turns*c[1]*c[0] + left*c[0]

		if dis > max {
			max = dis
		}
	}
	fmt.Println(max)
}

func q2(f *os.File, t int) {
	max := 0
	all := parse(f)
	score := make([]int, len(all), len(all))

	cur := func(t int, d []int) int {
		turns := t / (d[1] + d[2])
		left := t % (d[1] + d[2])
		if left > d[1] {
			left = d[1]
		}
		return turns*d[0]*d[1] + left*d[0]
	}

	for i := 1; i <= t; i++ {
		max = 0
		for j := 0; j < len(all); j++ {
			dis := cur(i, all[j])
			if dis > max {
				max = dis
			}
		}

		for j := 0; j < len(all); j++ {
			if cur(i, all[j]) == max {
				score[j]++
			}
		}
	}

	max = 0
	for _, s := range score {
		if s > max {
			max = s
		}
	}

	fmt.Println(max)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f, 2503)
	q2(f, 2503)
}
