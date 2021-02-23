// Easier solution!
package main

import (
	"bufio"
	"fmt"
	"os"
)

// 1 2 3
// 4 5 6
// 7 8 9
func q1(f *os.File) {
	input := bufio.NewScanner(f)
	var code []int

	x, y := 1, 1

	for input.Scan() {
		for _, c := range input.Text() {
			switch c {
			case 'U':
				if x != 0 {
					x -= 1
				}
			case 'D':
				if x != 2 {
					x += 1
				}
			case 'L':
				if y != 0 {
					y -= 1
				}
			case 'R':
				if y != 2 {
					y += 1
				}
			}
		}
		code = append(code, x*3+y+1)
	}
	fmt.Println(code)
}

func q2(f *os.File) {
	input := bufio.NewScanner(f)
	var code []byte
	x, y := 0, 0
	xs := []int{0, 1, 2, 1, 0}
	button := map[int]byte{
		0: '5', 1: '6', 2: '7', 3: '8', 4: '9', 6: 'A', 7: 'B', 8: 'C', 12: 'D',
		-4: '2', -3: '3', -2: '4', -8: '1'}

	for input.Scan() {
		for _, c := range input.Text() {
			switch c {
			case 'U':
				if x > -xs[y] {
					x -= 1
				}
			case 'D':
				if x < xs[y] {
					x += 1
				}
			case 'L':
				if y > -xs[x + 2] + 2{
					y -= 1
				}
			case 'R':
				if y < xs[x + 2] + 2 {
					y += 1
				}
			}
		}
		code = append(code, button[x*5+y])
	}
	fmt.Println(string(code))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
