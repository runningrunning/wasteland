package main

import (
	"fmt"
)

func round(in []int, lengths []int, cur, skip int) (int, int) {
	len := len(in)
	reverse := func(in []int, s, e int) {
		for i, j := s, e; i < j; i, j = i+1, j-1 {
			in[i%len], in[j%len] = in[j%len], in[i%len]
		}
	}

	for _, l := range lengths {
		cur %= len
		reverse(in, cur, cur+l-1)
		cur += l + skip
		skip += 1
	}

	return cur, skip
}

func knotHash(seed string) (int, []int) {
	lengths := make([]int, 0, len(seed)+5)
	for _, c := range []byte(seed) {
		lengths = append(lengths, int(c))
	}

	lengths = append(lengths, 17, 31, 73, 47, 23)
	numbers := make([]int, 0, 256)
	for i := 0; i < 256; i++ {
		numbers = append(numbers, i)
	}

	cur, skip := 0, 0
	for i := 0; i < 64; i++ {
		cur, skip = round(numbers, lengths, cur, skip)
	}

	sum := 0
	line := make([]int, 128, 128)

	for i := 0; i < 16; i++ {
		x := 0
		for j := 0; j < 16; j++ {
			x ^= numbers[i*16+j]
		}
		for j := 0; j < 8; j++ {
			if (x & (1 << (7 - j))) != 0 {
				sum += 1
				line[i*8+j] = 1
			} else {
				line[i*8+j] = 0
			}
		}

	}
	return sum, line
}

func q1(seed string) {
	sum := 0
	for i := 0; i < 128; i++ {
		t, _ := knotHash(fmt.Sprintf("%s-%d", seed, i))
		sum += t
	}
	fmt.Println(seed, sum)
}

func mark(m [][]int, x, y, s int) {
	m[x][y] = s

	if x != 0 && m[x-1][y] == 1 {
		mark(m, x-1, y, s)
	}

	if y != 0 && m[x][y-1] == 1 {
		mark(m, x, y-1, s)
	}

	if x != 127 && m[x+1][y] == 1 {
		mark(m, x+1, y, s)
	}

	if y != 127 && m[x][y+1] == 1 {
		mark(m, x, y+1, s)
	}
}

func q2(seed string) int {
	var maze [][]int

	for i := 0; i < 128; i++ {
		_, l := knotHash(fmt.Sprintf("%s-%d", seed, i))
		maze = append(maze, l)
	}

	s := 1
	for i := 0; i < 128; i++ {
		for j := 0; j < 128; j++ {
			if maze[i][j] == 1 {
				s += 1
				mark(maze, i, j, s)
			}
		}
	}
	fmt.Println(s - 1)
	return s - 1
}

func main() {
	q1("flqrgnkx")
	q1("amgozmfv")
	q2("flqrgnkx")
	q2("amgozmfv")
}
