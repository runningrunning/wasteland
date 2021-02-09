// careful ~!
package main

import (
	"bufio"
	"fmt"
	"os"
)

func out(seats [][]byte) {
	for _, i := range seats {
		for _, j := range i {
			fmt.Printf("%c", j)
		}
		fmt.Print("\n")
	}
	fmt.Print("\n")
}

func read(f *os.File) [][]byte {
	var seats [][]byte
	input := bufio.NewScanner(f)
	for input.Scan() {
		if len(input.Text()) == 0 {
			break
		}
		seats = append(seats, []byte(input.Text()))
	}
	return seats
}

func isOccupied(seats [][]byte, x, y int) bool {
	if x < 0 || y < 0 || x >= len(seats) || y >= len(seats[x]) {
		return false
	}
	return seats[x][y] == '#'
}

func turn(seats [][]byte, x, y int) byte {
	if seats[x][y] == '.' {
		return '.'
	}

	nearby := 0
	for i := -1; i <= 1; i++ {
		for j := -1; j <= 1; j++ {
			if isOccupied(seats, x+i, y+j) {
				nearby++
			}
		}
	}

	if seats[x][y] == '#' {
		nearby--
	}

	if seats[x][y] == 'L' && nearby == 0 {
		return '#'
	}

	if seats[x][y] == '#' && nearby >= 4 {
		return 'L'
	}

	return seats[x][y]
}

func isOccupied2(seats [][]byte, x, y int) (bool, bool) {
	if x < 0 || y < 0 || x >= len(seats) || y >= len(seats[x]) {
		return false, true
	}

	if seats[x][y] == '.' {
		return false, false
	}

	return seats[x][y] == '#', true
}

func turn2(seats [][]byte, x, y int) byte {
	if seats[x][y] == '.' {
		return '.'
	}

	nearby := 0
	for i := -1; i <= 1; i++ {
		for j := -1; j <= 1; j++ {
			if i == 0 && j == 0 {
				continue
			}
			si, sj := i, j
			for {
				o, s := isOccupied2(seats, x+si, y+sj)

				if s {
					if o {
						nearby++
					}
					break
				}

				si += i
				sj += j
			}

		}
	}

	if seats[x][y] == 'L' && nearby == 0 {
		return '#'
	}

	if seats[x][y] == '#' && nearby >= 5 {
		return 'L'
	}

	return seats[x][y]
}

func q1(f *os.File) {
	seats := read(f)

	// dup
	next := make([][]byte, len(seats))
	for i, j := range seats {
		next[i] = make([]byte, len(j))
		copy(next[i], j)
	}

	for {
		modified := false
		for i, s := range seats {
			for j, c := range s {
				n := turn(seats, i, j)
				if n != c {
					modified = true
				}
				next[i][j] = n
			}
		}

		t := seats
		seats = next
		next = t

		if !modified {
			break
		}
	}

	nums := 0
	for _, s := range seats {
		for _, c := range s {
			if c == '#' {
				nums++
			}
		}
	}

	fmt.Println(nums)
}

func q2(f *os.File) {
	seats := read(f)

	// dup
	next := make([][]byte, len(seats))
	for i, j := range seats {
		next[i] = make([]byte, len(j))
		copy(next[i], j)
	}

	for {
		modified := false
		for i, s := range seats {
			for j, c := range s {
				n := turn2(seats, i, j)
				if n != c {
					modified = true
				}
				next[i][j] = n
			}
		}

		t := seats
		seats = next
		next = t

		if !modified {
			break
		}
	}

	nums := 0
	for _, s := range seats {
		for _, c := range s {
			if c == '#' {
				nums++
			}
		}
	}

	fmt.Println(nums)
}

func main() {
	f, _ := os.Open(os.Args[1])
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Close()
}
