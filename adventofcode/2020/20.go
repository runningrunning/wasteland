// Use pointer, otherwise, it will not change the original value, like Used in Tile
// Just be careful !!!
// Speed up

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type Tile struct {
	ID   int
	Raw  []string
	R1   []int
	R2   []int
	Used bool
}

func output(in []*Tile) {
	for _, t := range in {
		fmt.Println(t.ID)
		for _, r := range t.Raw {
			fmt.Println(r)
		}
		fmt.Println(t.R1)
		fmt.Println(t.R2)
		fmt.Println("")
	}
}

func outputRaw(z [][]byte) {
	for _, x := range z {
		for _, y := range x {
			if y == 0 {
				fmt.Print(" ")
			} else {
				fmt.Printf("%c", y)
			}
		}
		fmt.Println("")
	}
	fmt.Println("")
}

func parser(f *os.File) ([]*Tile, map[int]int, map[int]int) {
	var all []*Tile
	cache := make(map[int]int)
	revert := make(map[int]int)
	input := bufio.NewScanner(f)
	for {
		t := Tile{}
		for input.Scan() {
			s := input.Text()

			if len(s) == 0 {
				break
			}

			if t.ID == 0 {
				t.R1 = make([]int, 4)
				t.R2 = make([]int, 4)
				fmt.Sscanf(s, "Tile %d:", &t.ID)
			} else {
				t.Raw = append(t.Raw, s)
				l := len(t.Raw)
				w := len(s)

				// should count the first and last line also
				if s[0] == '#' {
					t.R1[3] |= 1 << (l - 1)
					t.R2[1] |= 1 << (w - l)
				}

				if s[w-1] == '#' {
					t.R1[1] |= 1 << (w - l)
					t.R2[3] |= 1 << (l - 1)
				}

				// first or last line
				if l == 1 || l == w {
					for i, c := range s {
						if c == '#' {
							if l == 1 {
								t.R1[0] |= 1 << (w - 1 - i)
								t.R2[0] |= 1 << i
							} else {
								t.R1[2] |= 1 << i
								t.R2[2] |= 1 << (w - 1 - i)
							}
						}
					}
				}

			}
		}

		if t.ID == 0 {
			break
		}

		all = append(all, &t)

		for _, n := range t.R1 {
			cache[n]++
		}

		for _, n := range t.R2 {
			cache[n]++
		}

		revert[t.R1[0]] = t.R2[0]
		revert[t.R2[0]] = t.R1[0]
		revert[t.R1[1]] = t.R2[3]
		revert[t.R2[3]] = t.R1[1]
		revert[t.R1[2]] = t.R2[2]
		revert[t.R2[2]] = t.R1[2]
		revert[t.R1[3]] = t.R2[1]
		revert[t.R2[1]] = t.R1[3]

		// if t.ID == 1951 {
		// 	fmt.Println("==========start=========")
		// 	outputRaw(extract(&t))
		// 	fmt.Println("==========")
		// 	outputRaw(rotate(0, true, extract(&t)))
		// 	fmt.Println("==========")
		// 	outputRaw(rotate(1, true, extract(&t)))
		// 	fmt.Println("==========")
		// 	outputRaw(rotate(2, true, extract(&t)))
		// 	fmt.Println("==========")
		// 	outputRaw(rotate(3, true, extract(&t)))
		// }

	}
	output(all)
	fmt.Println(cache, revert)
	return all, cache, revert
}

func q1(f *os.File) {
	a, c, _ := parser(f)
	sum := 1
	for _, t := range a {
		count := 0
		for _, n := range t.R1 {
			if c[n] == 1 {
				count++
			}
		}

		for _, n := range t.R2 {
			if c[n] == 1 {
				count++
			}
		}

		if count == 4 {
			fmt.Println(t.ID)
			sum *= t.ID
		}
	}
	fmt.Println(sum)
}

func extract(t *Tile) (m [][]byte) {
	m = make([][]byte, len(t.Raw)-2)

	for i := 1; i < len(t.Raw)-1; i++ {
		m[i-1] = make([]byte, len(t.Raw[i])-2)
		for j := 1; j < len(t.Raw[i])-1; j++ {
			m[i-1][j-1] = t.Raw[i][j]
		}
	}

	return m
}

func rotate(times int, flip bool, in [][]byte) [][]byte {
	// fmt.Println("Rotate", times)
	w, h := len(in[0]), len(in)

	if flip {
		for _, line := range in {
			for i, j := 0, w-1; i < j; i, j = i+1, j-1 {
				line[i], line[j] = line[j], line[i]
			}
		}
	}

	if times == 0 {
		return in
	}

	m := make([][]byte, w)

	for i := 0; i < w; i++ {
		m[i] = make([]byte, h)
		for j := 0; j < h; j++ {
			m[i][j] = in[h-1-j][i]
		}
	}

	return rotate(times-1, false, m)
}

func find(left int, top int, all []*Tile, cache map[int]int, revert map[int]int) (int, int, [][]byte) {
	fmt.Println("Got nil start", left, top)
	for _, t := range all {
		if t.Used {
			continue
		}

		for i := 0; i < 4; i++ {
			if ((left == 0 && cache[t.R1[i]] == 1) || left == t.R1[i]) &&
				((top == 0 && cache[t.R1[(i+1)%4]] == 1) || top == t.R1[(i+1)%4]) {
				t.Used = true
				fmt.Println("Use ", t.ID)
				return t.R1[(i+2)%4], t.R1[(i+1+2)%4], rotate(4-1-i, false, extract(t))
			}
		}

		for i := 0; i < 4; i++ {
			if ((left == 0 && cache[t.R2[i]] == 1) || left == t.R2[i]) &&
				((top == 0 && cache[t.R2[(i+1)%4]] == 1) || top == t.R2[(i+1)%4]) {
				t.Used = true
				fmt.Println("Use ", t.ID)
				return t.R2[(i+2)%4], t.R2[(i+1+2)%4], rotate(4-1-i, true, extract(t))
			}
		}

		if left != 0 {
			left = revert[left]
		}

		if top != 0 {
			top = revert[top]
		}

		fmt.Println("Again ", left, top)

		for i := 0; i < 4; i++ {
			if ((left == 0 && cache[t.R1[i]] == 1) || left == t.R1[i]) &&
				((top == 0 && cache[t.R1[(i+1)%4]] == 1) || top == t.R1[(i+1)%4]) {
				t.Used = true
				fmt.Println("Use ", t.ID)
				return t.R1[(i+2)%4], t.R1[(i+1+2)%4], rotate(4-1-i, false, extract(t))
			}
		}

		for i := 0; i < 4; i++ {
			if ((left == 0 && cache[t.R2[i]] == 1) || left == t.R2[i]) &&
				((top == 0 && cache[t.R2[(i+1)%4]] == 1) || top == t.R2[(i+1)%4]) {
				t.Used = true
				fmt.Println("Use ", t.ID)
				return t.R2[(i+2)%4], t.R2[(i+1+2)%4], rotate(4-1-i, true, extract(t))
			}
		}

	}
	fmt.Println("Got nil end", left, top)
	return 0, 0, nil
}

func match(p [][]byte, a [][]byte) {
	py, px := len(p), len(p[0])
	ay, ax := len(a), len(a[0])

	for y := 0; y < ay-py; y++ {
		for x := 0; x < ax-px; x++ {
			ok := true

			for i := 0; i < py; i++ {
				for j := 0; j < px; j++ {
					if p[i][j] == 0 {
						continue
					}

					if p[i][j] == '#' && ('#' != a[y+i][x+j] && 'O' != a[y+i][x+j]) {
						ok = false
						break
					}
				}
				if !ok {
					break
				}
			}

			if ok {
				fmt.Println("got here.\n")
				for i := 0; i < py; i++ {
					for j := 0; j < px; j++ {
						if p[i][j] == '#' {
							a[y+i][x+j] = 'O'
						}
					}
				}
			}
		}
	}
}

func q2(f *os.File) {
	a, c, r := parser(f)
	n := int(math.Sqrt(float64(len(a))))
	w := n * 8
	all := make([][]byte, w)
	for i := 0; i < w; i++ {
		all[i] = make([]byte, w)
	}

	left := 0
	top := make([]int, n)

	for i := 0; i < len(a); i++ {
		if (i % n) == 0 {
			left = 0
		}
		right, bottom, area := find(left, top[i%n], a, c, r)

		// fmt.Println(right, bottom)
		// outputRaw(area)

		for j := 0; j < 8; j++ {
			for k := 0; k < 8; k++ {
				all[j+(i/n)*8][k+(i%n)*8] = area[j][k]
			}
		}

		top[i%n] = bottom
		left = right
	}

	pattern := []string{"                  # ", "#    ##    ##    ###", " #  #  #  #  #  #   "}

	bpattern := make([][]byte, len(pattern))

	for i, p := range pattern {
		bpattern[i] = make([]byte, len(p))
		for j, x := range p {
			if x == '#' {
				fmt.Println(j, x)
				bpattern[i][j] = '#'
			}
		}
	}

	// fmt.Println(pattern, len(pattern))
	// outputRaw(bpattern)

	fmt.Println("before running")
	outputRaw(all)
	for i := 0; i < 4; i++ {
		z := rotate(i, false, bpattern)
		match(z, all)
	}

	bpattern = rotate(0, true, bpattern)
	for i := 0; i < 4; i++ {
		z := rotate(i, false, bpattern)
		match(z, all)
	}
	outputRaw(all)
	sum := 0
	for _, x := range all {
		for _, y := range x {
			if y == '#' {
				sum++
			}
		}
	}

	fmt.Println(sum)

	// verify it works !
	// for i := 0; i < 4; i++ {
	// 	z := rotate(i, false, all)
	// 	for _, x := range z {
	// 		for _, y := range x {
	// 			fmt.Printf("%c", y)
	// 		}
	// 		fmt.Println("")
	// 	}

	// 	fmt.Println("")
	// 	fmt.Println("")
	// }

	// all = rotate(0, true, all)
	// for i := 0; i < 4; i++ {
	// 	z := rotate(i, false, all)
	// 	for _, x := range z {
	// 		for _, y := range x {
	// 			fmt.Printf("%c", y)
	// 		}
	// 		fmt.Println("")
	// 	}

	// 	fmt.Println("")
	// 	fmt.Println("")
	// }

}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
