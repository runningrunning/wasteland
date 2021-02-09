package main

import (
	"bufio"
	"fmt"
	"os"
)

func cube(d int) [][][][]byte {
	c := make([][][][]byte, d)
	for i := 0; i < d; i++ {
		c[i] = make([][][]byte, d)
		for j := 0; j < d; j++ {
			c[i][j] = make([][]byte, d)
			for k := 0; k < d; k++ {
				c[i][j][k] = make([]byte, d)
			}
		}
	}
	return c
}

func read(c [][][][]byte, o [][]byte, s int) {
	for x, ox := range o {
		for y, oxy := range ox {
			if oxy == '#' {
				// read into the middle of z, w
				c[x+s][y+s][len(c)/2][len(c)/2] = '#'
			}
		}
	}
}

func count(c [][][][]byte) int {
	num := 0
	for _, x := range c {
		for _, y := range x {
			for _, z := range y {
				for _, w := range z {
					if w == '#' {
						num++
					}
				}
			}
		}
	}
	return num
}

func parser(f *os.File) (o [][]byte, d int) {
	input := bufio.NewScanner(f)
	x := 0
	for input.Scan() {
		o = append(o, make([]byte, len(input.Text())))
		for y, c := range input.Text() {
			if c == '#' {
				o[x][y] = '#'
			}
		}
		x++
	}
	return o, x
}

// include itself
func surround(o [][][][]byte, x, y, z, w int) int {
	num := 0
	for i := -1; i <= 1; i++ {
		for j := -1; j <= 1; j++ {
			for k := -1; k <= 1; k++ {
				for l := -1; l <= 1; l++ {
					if o[x+i][y+j][z+k][w+l] == '#' {
						num++
						if num > 4 {
							return num
						}
					}
				}
			}
		}
	}
	return num
}

func conv(n, o [][][][]byte) {
	for x := 1; x < len(o)-1; x++ {
		for y := 1; y < len(o)-1; y++ {
			for z := 1; z < len(o)-1; z++ {
				for w := 1; w < len(o)-1; w++ {
					s := surround(o, x, y, z, w)
					if s == 3 {
						n[x][y][z][w] = '#'
					} else if s == 4 && o[x][y][z][w] == '#' {
						n[x][y][z][w] = '#'
					} else {
						n[x][y][z][w] = 0
					}
				}
			}
		}
	}
}

func q1(f *os.File) {
	i, d := parser(f)
	o := cube(d + 18)
	n := cube(d + 18)
	read(o, i, 9)

	for x := 0; x < 6; x++ {
		conv(n, o)
		o, n = n, o
	}
	fmt.Println(count(o))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
