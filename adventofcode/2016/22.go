package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	x, y, size, used, avail, use int
}

func draw(mz [][]byte) {
	for i := 0; i < len(mz); i++ {
		fmt.Println(string(mz[i]))
	}
	fmt.Println()
}

func steps(mz [][]byte, cx, cy, x, y int) int {
	if cy != 0 {
		if mz[cy-1][cx] != '#' {
			return 1 + steps(mz, cx, cy - 1, x, y)
		} else {
			return 1 + steps(mz, cx-1, cy, x, y)
		}
	}

	if cx == x {
		return 0
	}
	return 1 + steps(mz, cx + 1, cy, x, y)
}

func q1(f *os.File) [][]byte {
	input := bufio.NewScanner(f)

	var all []Node
	max_x, max_y := 0, 0

	for input.Scan() {
		if strings.HasPrefix(input.Text(), "root") || strings.HasPrefix(input.Text(), "FilesSystem") {
			continue
		}
		ws := strings.Split(input.Text(), " ")
		wi := 0

		for _, w := range ws {
			if w != "" {
				ws[wi] = w
				wi++
			}
		}

		toInt := func(i int) int {
			// skip the last T/%
			n, _ := strconv.Atoi(ws[i][:len(ws[i])-1])
			return n
		}

		var x, y int
		fmt.Sscanf(ws[0], "/dev/grid/node-x%d-y%d", &x, &y)

		if x > max_x {
			max_x = x
		}

		if y > max_y {
			max_y = y
		}

		all = append(all, Node{x, y, toInt(1), toInt(2), toInt(3), toInt(4)})
	}

	sum := 0

	// // Should compare both i,j and j,i
	// for i := 0; i < len(all); i ++ {
	// 	for j := i + 1; j < len(all); j ++ {
	// 		if all[i].used != 0 && all[i].used <= all[j].avail {
	// 			sum ++
	// 		}
	// 		if all[j].used != 0 && all[j].used <= all[i].avail {
	// 			sum ++
	// 		}
	// 	}
	// }

	maze := make([][]byte, max_y+1, max_y+1)

	for i := 0; i <= max_y; i++ {
		maze[i] = make([]byte, max_x+1, max_x+1)
		for j := 0; j <= max_x; j++ {
			maze[i][j] = '#'
		}
	}

	avail_x, avail_y := 0, 0

	for i := 0; i < len(all); i++ {
		if all[i].used == 0 {
			continue
		}
		for j := 0; j < len(all); j++ {
			if i == j {
				continue
			}

			if all[i].used <= all[j].avail {
				avail_x = all[j].x
				avail_y = all[j].y
				sum++
				maze[all[i].y][all[i].x] = '.'
				maze[all[j].y][all[j].x] = '_'
			}
		}
	}

	maze[0][0] = 'E'
	maze[0][max_x] = 'G'
	draw(maze)
	fmt.Println(sum, max_y, max_x, avail_y, avail_x)

	// '_' to 'G'
	st := steps(maze, avail_x, avail_y, max_x, 0)
	// Move G one step forward need 5 Steps
	// X number - E - G = (max_x + 1) - 2
	st += ((max_x + 1) - 2) * 5
	fmt.Println(st)
	return maze
}

// E...................................G
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................
// .....################################
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................
// ......._.............................
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................
// .....................................

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
