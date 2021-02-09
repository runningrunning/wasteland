// be careful
package main

import (
	"fmt"
)

func bio(s [][]byte) int {
	point := 0
	for i, row := range s {
		for j, c := range row {
			if c == '#' {
				point += 1 << (i*5 + j)
			}
		}
	}
	return point
}

func around(s [][]byte, x, y int) int {
	a := 0
	if x > 0 && s[x-1][y] == '#' {
		a += 1
	}

	if y > 0 && s[x][y-1] == '#' {
		a += 1
	}

	if x < 4 && s[x+1][y] == '#' {
		a += 1
	}

	if y < 4 && s[x][y+1] == '#' {
		a += 1
	}
	return a
}

func output(s [][]byte) {
	for _, row := range s {
		fmt.Println(string(row))
	}
	fmt.Println()
}

func run(s [][]byte) (n [][]byte) {
	for i := 0; i < 5; i++ {
		n = append(n, make([]byte, 5, 5))
		for j := 0; j < 5; j++ {
			a := around(s, i, j)

			if s[i][j] == '#' {
				if a == 1 {
					n[i][j] = '#'
				} else {
					n[i][j] = '.'
				}
			} else {
				if a == 1 || a == 2 {
					n[i][j] = '#'
				} else {
					n[i][j] = '.'
				}
			}
		}
	}
	return n
}

func q1(s [][]byte) {

	ps := make(map[int]int)
	for {
		output(s)
		n := bio(s)
		if ps[n] == 1 {
			fmt.Println("Again ", bio(s))
			return
		}
		ps[n] = 1
		s = run(s)
	}
}

func count(s [][][]byte) int {
	sum := 0
	for _, c := range s {
		for i := 0; i < 5; i++ {
			for j := 0; j < 5; j++ {
				if i == 2 && j == 2 {
					continue
				}

				if c[i][j] == '#' {
					sum += 1
				}
			}
		}
	}
	return sum
}

func matrix() (n [][]byte) {
	n = append(n, make([]byte, 5, 5))
	n = append(n, make([]byte, 5, 5))
	n = append(n, make([]byte, 5, 5))
	n = append(n, make([]byte, 5, 5))
	n = append(n, make([]byte, 5, 5))
	return n
}

func around2(s [][][]byte, x, y, cur, pre, nxt int) int {
	a := 0

	// x - 1
	if x == 0 {
		if pre != -1 {
			if s[pre][1][2] == '#' {
				a += 1
			}
		}
	} else {
		if x == 3 && y == 2 {
			if nxt != -1 {
				for k := 0; k < 5; k++ {
					if s[nxt][4][k] == '#' {
						a += 1
					}
				}
			}
		} else {
			if s[cur][x-1][y] == '#' {
				a += 1
			}
		}
	}

	// y - 1
	if y == 0 {
		if pre != -1 {
			if s[pre][2][1] == '#' {
				a += 1
			}
		}
	} else {
		if y == 3 && x == 2 {
			if nxt != -1 {
				for k := 0; k < 5; k++ {
					if s[nxt][k][4] == '#' {
						a += 1
					}
				}
			}
		} else {
			if s[cur][x][y-1] == '#' {
				a += 1
			}
		}
	}

	// x + 1
	if x == 4 {
		if pre != -1 {
			if s[pre][3][2] == '#' {
				a += 1
			}
		}
	} else {
		if x == 1 && y == 2 {
			if nxt != -1 {
				for k := 0; k < 5; k++ {
					if s[nxt][0][k] == '#' {
						a += 1
					}
				}
			}
		} else {
			if s[cur][x+1][y] == '#' {
				a += 1
			}
		}
	}

	// y + 1
	if y == 4 {
		if pre != -1 {
			if s[pre][2][3] == '#' {
				a += 1
			}
		}
	} else {
		if y == 1 && x == 2 {
			if nxt != -1 {
				for k := 0; k < 5; k++ {
					if s[nxt][k][0] == '#' {
						a += 1
					}
				}
			}
		} else {
			if s[cur][x][y+1] == '#' {
				a += 1
			}
		}
	}
	return a
}

func run2(s [][][]byte) (n [][][]byte) {
	pre := -1
	nxt := -1
	extend := false

	outer := s[0]

	for i := 0; i < 5; i ++ {
		if outer[0][i] == '#' {
			extend = true
		}

		if outer[4][i] == '#' {
			extend = true
		}

		if outer[i][4] == '#' {
			extend = true
		}

		if outer[i][0] == '#' {
			extend = true
		}

		if extend {
			break
		}
	}

	if extend {
		var ns [][][]byte
		ns = append(ns, matrix())
		s = append(ns, s...)
	}

	extend = false

	inner := s[len(s)-1]
	for i := 1; i < 4; i++ {
		for j := 1; j < 4; j++ {
			if i == 2 && j == 2 {
				continue
			}

			if inner[i][j] == '#' {
				extend = true
				break
			}
		}

		if extend {
			break
		}
	}

	if extend {
		s = append(s, matrix())
	}

	for c := 0; c < len(s); c++ {
		nxt = c + 1
		if nxt == len(s) {
			nxt = -1
		}
		x := matrix()
		for i := 0; i < 5; i++ {
			for j := 0; j < 5; j++ {
				if i == 2 && j == 2 {
					continue
				}

				a := around2(s, i, j, c, pre, nxt)
				if s[c][i][j] == '#' {
					if a == 1 {
						x[i][j] = '#'
					} else {
						x[i][j] = '.'
					}
				} else {
					if a == 1 || a == 2 {
						x[i][j] = '#'
					} else {
						x[i][j] = '.'
					}
				}
			}
		}
		n = append(n, x)
		pre = c
	}
	return n
}

func q2(s [][]byte) {
	var t [][][]byte
	t = append(t, s)

	for i := 0; i < 200; i++ {
		t = run2(t)
		fmt.Println(i+1, count(t))
	}
}

func main() {
	s := [][]byte{

		// // // test
		// []byte("....#"),
		// []byte("#..#."),
		// []byte("#..##"),
		// []byte("..#.."),
		// []byte("#...."),

		[]byte(".#.##"),
		[]byte("...#."),
		[]byte("....#"),
		[]byte(".#..."),
		[]byte("..#.."),

	}

	// q1(s)
	q2(s)
}
