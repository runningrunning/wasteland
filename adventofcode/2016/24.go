// How to genreate full sequence ?
package main

import (
	"bufio"
	"fmt"
	"os"
)

func parser(f *os.File) (maze [][]byte, loc map[int][]int) {
	input := bufio.NewScanner(f)
	loc = make(map[int][]int)

	for input.Scan() {
		maze = append(maze, []byte(input.Text()))
	}

	for i := 0; i < len(maze); i++ {
		for j := 0; j < len(maze[i]); j++ {
			if maze[i][j] >= '0' && maze[i][j] <= '9' {
				loc[int(maze[i][j]-'0')] = []int{j, i}
			}
		}
	}
	return
}

func output(maze [][]byte) {
	for _, l := range maze {
		fmt.Println(string(l))
	}
	fmt.Println()
}

func distance(maze [][]byte, x, y int) map[int]int {
	// y << 16 | x
	visited := make(map[int]bool)
	distances := make(map[int]int)

	hash := func(x, y int) int {
		return y<<16 | x
	}

	var a, b []int
	a = append(a, hash(x, y))

	can := func(x, y int) bool {
		return x >= 0 && x < len(maze[0]) && y >= 0 && y < len(maze) && maze[y][x] != '#' && !visited[hash(x, y)]
	}

	steps := 0

	for {
		for _, c := range a {
			cx, cy := c&0xFFFF, c>>16

			if maze[cy][cx] >= '0' && maze[cy][cx] <= '9' {
				if _, ok := distances[int(maze[cy][cx]-'0')]; !ok {
					distances[int(maze[cy][cx]-'0')] = steps
				}
			}

			if can(cx-1, cy) {
				visited[hash(cx-1, cy)] = true
				b = append(b, hash(cx-1, cy))
			}

			if can(cx+1, cy) {
				visited[hash(cx+1, cy)] = true
				b = append(b, hash(cx+1, cy))
			}

			if can(cx, cy-1) {
				visited[hash(cx, cy-1)] = true
				b = append(b, hash(cx, cy-1))
			}

			if can(cx, cy+1) {
				visited[hash(cx, cy+1)] = true
				b = append(b, hash(cx, cy+1))
			}
		}

		a, b = b, a
		b = nil
		steps++

		if len(a) == 0 {
			break
		}
	}
	return distances
}

func short(ds map[int]map[int]int, c, path int, used map[int]bool, min *int) {
	if path >= *min {
		return
	}

	found := false

	for n, p := range ds[c] {
		if n == c || used[n] {
			continue
		}
		used[n] = true
		short(ds, n, path+p, used, min)
		used[n] = false
		found = true
	}

	if !found {
		// back to 0 should add ds[c][0]
		if path + ds[c][0] < *min {
			*min = path + ds[c][0]
		}
	}
}

func q1(f *os.File) {
	m, l := parser(f)
	output(m)
	fmt.Println(l)
	distances := make(map[int]map[int]int)

	for _, p := range l {
		distances[int(m[p[1]][p[0]]-'0')] = distance(m, p[0], p[1])
	}

	min := int((^uint(0)) >> 1)
	used := make(map[int]bool)
	// start from 0
	used[0] = true

	short(distances, 0, 0, used, &min)
	fmt.Println(min)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
