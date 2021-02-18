// Be careful
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func output(grid []string) {
	for _, l := range grid {
		fmt.Println(l)
	}
	fmt.Println()
}

func count(grid []string) int {
	sum := 0
	for _, y := range grid {
		for _, c := range y {
			if c == '#' {
				sum += 1
			}
		}
	}
	return sum
}

func round(input []string, conv map[string]string) []string {
	rl, step := 0, 2

	if (len(input) % 2) == 0 {
		step = 2
		rl = len(input) / 2 * 3
	} else {
		step = 3
		rl = len(input) / 3 * 4
	}

	result := make([][]byte, rl, rl)
	for i := 0; i < rl; i++ {
		result[i] = make([]byte, rl, rl)
	}

	for i := 0; i < len(input)/step; i++ {
		for j := 0; j < len(input[0])/step; j++ {
			t := ""
			for k := 0; k < step; k++ {
				for l := 0; l < step; l++ {
					t += string(input[i*step+k][j*step+l])
				}
			}

			tile := strings.Split(conv[t], "/")

			for k := 0; k < len(tile); k++ {
				for l := 0; l < len(tile[0]); l++ {
					result[i*len(tile)+k][j*len(tile[0])+l] = tile[k][l]
				}
			}
		}
	}

	var r []string

	for _, l := range result {
		r = append(r, string(l))
	}
	return r
}

func flip(in []string) []string {
	var ret []string

	for _, l := range in {
		t := ""
		for _, c := range l {
			t = string(c) + t
		}
		ret = append(ret, t)
	}
	return ret
}

func rotate(in []string) []string {
	var ret []string

	for i := 0; i < len(in[0]); i++ {
		t := ""
		for j := len(in) - 1; j >= 0; j-- {
			t += string(in[j][i])
		}
		ret = append(ret, t)
	}
	return ret
}

func enum(in string) []string {
	var ret []string
	sample := strings.Split(in, "/")

	for i := 0; i < 4; i++ {
		ret = append(ret, strings.Join(sample, ""))
		sample = rotate(sample)
	}

	sample = flip(sample)

	for i := 0; i < 4; i++ {
		ret = append(ret, strings.Join(sample, ""))
		sample = rotate(sample)
	}
	return ret
}

func q1(f *os.File, turns int) {
	input := bufio.NewScanner(f)
	conv := make(map[string]string)
	for input.Scan() {
		lines := strings.Split(input.Text(), " => ")
		for _, x := range enum(lines[0]) {
			conv[x] = lines[1]
		}
	}

	s := []string{".#.", "..#", "###"}
	for i := 0; i < turns; i++ {
		// output(s)
		s = round(s, conv)
	}
	// output(s)
	fmt.Println(count(s))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f, 5)
	f.Seek(0, 0)
	q1(f, 18)
}
