package main

import (
	"bufio"
	"fmt"
	"os"
)

func parse(f *os.File) (all [][]byte) {
	f.Seek(0, 0)
	input := bufio.NewScanner(f)
	for input.Scan() {
		all = append(all, []byte(input.Text()))
	}
	return all
}

func count(in [][]byte) int {
	sum := 0
	for _, l := range in {
		for _, c := range l {
			if c == '#' {
				sum++
			}
		}
	}
	return sum
}

func round(in [][]byte) (out [][]byte) {
	around := func(x, y int) int {
		sum := 0
		for i := -1; i <= 1; i++ {
			for j := -1; j <= 1; j++ {
				if i == 0 && j == 0 {
					continue
				}

				if x+i < 0 || x+i >= len(in) {
					continue
				}

				if y+j < 0 || y+j >= len(in[x]) {
					continue
				}

				if in[x+i][y+j] == '#' {
					sum++
				}
			}
		}
		return sum
	}

	for x := 0; x < len(in); x++ {
		t := make([]byte, len(in[x]), len(in[x]))
		for y := 0; y < len(in[x]); y++ {
			a := around(x, y)
			if a == 3 || (a == 2 && in[x][y] == '#') {
				t[y] = '#'
			} else {
				t[y] = '.'
			}
		}
		out = append(out, t)
	}
	return
}

func q1(f *os.File, t int) int {
	all := parse(f)
	for i := 0; i < t; i++ {
		all = round(all)
	}
	return count(all)
}

func q2(f *os.File, t int) int {
	all := parse(f)

	all[0][0] = '#'
	all[0][len(all[0])-1] = '#'
	all[len(all)-1][0] = '#'
	all[len(all)-1][len(all[0])-1] = '#'

	for i := 0; i < t; i++ {
		all = round(all)

		// reset the corner
		all[0][0] = '#'
		all[0][len(all[0])-1] = '#'
		all[len(all)-1][0] = '#'
		all[len(all)-1][len(all[0])-1] = '#'
	}
	return count(all)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	fmt.Println(q1(f, 100))
	fmt.Println(q2(f, 100))
}
