package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func parse(f *os.File) (all [][]int) {
	input := bufio.NewScanner(f)

	toInt := func(s string) int {
		if s[len(s)-1] == ',' {
			s = s[:len(s)-1]
		}
		n, _ := strconv.Atoi(s)
		return n
	}
	for input.Scan() {
		ws := strings.Split(input.Text(), " ")
		var c []int
		c = append(c, toInt(ws[2]))
		c = append(c, toInt(ws[4]))
		c = append(c, toInt(ws[6]))
		c = append(c, toInt(ws[8]))
		c = append(c, toInt(ws[10]))
		all = append(all, c)
	}
	return
}

func best(all [][]int, c, left int, ingredients []int, max *int) {
	if c == len(all) - 1 {
		ingredients[c] = left
		scores := make([]int, len(all[0]), len(all[0]))
		for i := 0; i < len(all); i++ {
			for j := 0; j < len(all[i]); j++ {
				scores[j] += ingredients[i] * all[i][j]
			}
		}

		// q2, 500 calories
		if scores[len(scores)-1] != 500 {
			return
		}

		score := 1

		// don't count calories
		for j := 0; j < len(all[0])-1; j++ {
			if scores[j] <= 0 {
				return
			}
			score *= scores[j]
		}

		if score > *max {
			*max = score
		}
	} else {
		if left == 0 {
			return
		}

		for i := 1; i <= left; i++ {
			ingredients[c] = i
			best(all, c+1, left-i, ingredients, max)
		}
	}
}

func q1(f *os.File, n int) {
	all := parse(f)
	max := 0
	ingredients := make([]int, len(all), len(all))
	best(all, 0, 100, ingredients, &max)
	fmt.Println(max)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f, 100)
}
