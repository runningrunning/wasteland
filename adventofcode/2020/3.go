package main

import (
	"bufio"
	"fmt"
	"os"
)

func crosses(area [][]byte, nx int, ny int) int {
	trees := 0
	x := 0
	y := 0
	w := len(area[0])
	h := len(area)

	for true {
		x += nx
		y += ny
		x %= w

		if y >= h {
			break
		}

		if area[y][x] == '#' {
			trees++
		}
	}
	return trees
}

func q1(f *os.File) int {
	var area [][]byte
	input := bufio.NewScanner(f)
	for input.Scan() {
		area = append(area, []byte(input.Text()))
	}
	return crosses(area, 3, 1)
}

func q2(f *os.File) int {
	var area [][]byte
	input := bufio.NewScanner(f)
	for input.Scan() {
		area = append(area, []byte(input.Text()))
	}
	return crosses(area, 1, 1) * crosses(area, 3, 1) * crosses(area, 5, 1) * crosses(area, 7, 1) * crosses(area, 1, 2)
}

func main() {
	f, _ := os.Open(os.Args[1:][0])
	fmt.Println(q1(f))
	f.Seek(0, 0)
	fmt.Println(q2(f))
	f.Close()
}
