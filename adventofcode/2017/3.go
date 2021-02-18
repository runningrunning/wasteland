// Just be careful
// find better solution
package main

import (
	"fmt"
	"os"
)

func q1(i int) {
	s := 1
	x, y := 0, 0

	i -= 1

	for i != 0 {
		if i < s {
			y += i
			break
		} else {
			y += s
			i -= s
			if i < s {
				x += i
				break
			} else {
				x += s
				i -= s
				s += 1

				if i < s {
					y -= i
					break
				} else {
					y -= s
					i -= s

					if i < s {
						x -= i
						break
					} else {
						x -= s
						i -= s
						s += 1
					}
				}
			}
		}
	}

	if x < 0 {
		x = -x
	}

	if y < 0 {
		y = -y
	}

	fmt.Println(x + y)
}

func v2(maze [][]int, x, y, max int) int {
	v := 0
	for i := -1; i <= 1; i++ {
		for j := -1; j <= 1; j++ {
			v += maze[x+i][y+j]
		}
	}

	if v >= max {
		fmt.Println(v)
		os.Exit(0)
	}

	fmt.Printf("%d ", v)
	return v
}

func q2(max int) {
	maze := make([][]int, 1024)
	for i := 0; i < 1024; i++ {
		maze[i] = make([]int, 1024)
	}

	x, y := 512, 512

	maze[x][y] = 1
	s := 1

	for {
		for i := 1; i <= s; i++ {
			maze[x][y+i] = v2(maze, x, y+i, max)
		}

		y += s

		for i := 1; i <= s; i++ {
			maze[x+i][y] = v2(maze, x+i, y, max)
		}

		x += s
		s += 1

		for i := 1; i <= s; i++ {
			maze[x][y-i] = v2(maze, x, y-i, max)
		}

		y -= s

		for i := 1; i <= s; i++ {
			maze[x-i][y] = v2(maze, x-i, y, max)
		}
		x -= s
		s += 1
	}
}

func main() {
	q1(1)
	q1(12)
	q1(23)
	q1(1024)
	q1(347991)
	q2(347991)
}
