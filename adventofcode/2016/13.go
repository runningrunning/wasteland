package main

import (
	"fmt"
)

func space(fav, x, y int) bool {
	if x < 0 || y < 0 {
		return false
	}

	t := x*x + 3*x + 2*x*y + y + y*y + fav

	sum := 0
	for t != 0 {
		sum++
		t &= t - 1
	}

	return (sum & 1) == 0
}

func q1(fav int, r, w int) int {

	// x << 16 + y
	visited := make(map[int]bool)

	x, y := 1, 1

	hash := func(x, y int) int {
		return x<<16 | y
	}

	var a, b []int

	a = append(a, hash(x, y))
	visited[hash(x, y)] = true

	cur := 0

	for {
		for _, c := range a {
			x, y = (c>>16)&0xFFFF, c&0xFFFF

			if x == r && y == w {
				return cur
			}

			if space(fav, x-1, y) && !visited[hash(x-1, y)] {
				visited[hash(x-1, y)] = true
				b = append(b, hash(x-1, y))
			}

			if space(fav, x+1, y) && !visited[hash(x+1, y)] {
				visited[hash(x+1, y)] = true
				b = append(b, hash(x+1, y))
			}

			if space(fav, x, y-1) && !visited[hash(x, y-1)] {
				visited[hash(x, y-1)] = true
				b = append(b, hash(x, y-1))
			}

			if space(fav, x, y+1) && !visited[hash(x, y+1)] {
				visited[hash(x, y+1)] = true
				b = append(b, hash(x, y+1))
			}
		}

		a, b = b, a
		b = nil
		cur++
	}
	return -1
}

func q2(fav int, steps int) int {
	// x << 16 + y
	visited := make(map[int]bool)

	x, y := 1, 1

	hash := func(x, y int) int {
		return x<<16 | y
	}

	var a, b []int

	a = append(a, hash(x, y))
	visited[hash(x, y)] = true

	for i:= 0; i < steps; i ++ {
		for _, c := range a {
			x, y = (c>>16)&0xFFFF, c&0xFFFF

			if space(fav, x-1, y) && !visited[hash(x-1, y)] {
				visited[hash(x-1, y)] = true
				b = append(b, hash(x-1, y))
			}

			if space(fav, x+1, y) && !visited[hash(x+1, y)] {
				visited[hash(x+1, y)] = true
				b = append(b, hash(x+1, y))
			}

			if space(fav, x, y-1) && !visited[hash(x, y-1)] {
				visited[hash(x, y-1)] = true
				b = append(b, hash(x, y-1))
			}

			if space(fav, x, y+1) && !visited[hash(x, y+1)] {
				visited[hash(x, y+1)] = true
				b = append(b, hash(x, y+1))
			}
		}

		a, b = b, a
		b = nil
	}
	return len(visited)
}

func main() {
	fmt.Println(q1(10, 7, 4))
	fmt.Println(q1(1358, 31, 39))
	fmt.Println(q2(10, 50))
	fmt.Println(q2(1358, 50))
}
