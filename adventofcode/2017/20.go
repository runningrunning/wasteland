package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Particle [][]int

func Abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}

func xyz(s []int) int {
	return Abs(s[0]) + Abs(s[1]) + Abs(s[2])
}

func (p Particle) Len() int {
	return len(p)
}

func (p Particle) Less(i, j int) bool {
	ai := xyz(p[i][6:])
	aj := xyz(p[j][6:])

	if ai != aj {
		return ai < aj
	}

	vi := xyz(p[i][3:])
	vj := xyz(p[j][3:])

	if vj != vj {
		return vi < vj
	}

	pi := xyz(p[i])
	pj := xyz(p[j])
	return pi < pj
}

func (p Particle) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func same(i, j []int, t int) bool {
	if t < 0 {
		return false
	}

	// a*x*x + b*x + c = 0
	for k := 0; k < 3; k++ {
		ki := i[k] + t*i[k+3] + (1+t)*t*i[k+6]/2
		kj := j[k] + t*j[k+3] + (1+t)*t*j[k+6]/2
		if ki != kj {
			return false
		}
	}
	return true
}

func collide(i, j []int) bool {

	if i[6] == j[6] {
		b := float64(2*(i[3]-j[3]) + i[6] - j[6])
		c := float64(2 * (i[0] - j[0]))
		if i[3] == j[3] {
			return same(i, j, 0)
		}
		x := -c / b
		if x >= 0.0 {
			return same(i, j, int(x))
		}
	} else {
		// solve a*x*x + b*x + c = 0
		// only do it for X and verify it on Y, Z
		a := float64(i[6] - j[6])
		b := float64(2*(i[3]-j[3]) + i[6] - j[6])
		c := float64(2 * (i[0] - j[0]))

		if (b*b - 4*a*c) < 0.0 {
			return false
		}

		t := math.Sqrt(b*b - 4*a*c)
		x := (-b + t) / (2 * a)

		if x >= 0.0 {
			if same(i, j, int(x)) {
				return true
			}
		}

		x = (-b - t) / (2 * a)
		if x >= 0.0 {
			if same(i, j, int(x)) {
				return true
			}
		}
	}
	return false
}

func q1(f *os.File) {
	var all Particle
	input := bufio.NewScanner(f)
	id := 0
	for input.Scan() {
		line := input.Text()
		in := ""

		for _, x := range line {
			if x == '-' || x == ',' || (x >= '0' && x <= '9') {
				in += string(x)
			}
		}

		var vs []int
		for _, i := range strings.Split(in, ",") {
			x, _ := strconv.Atoi(i)
			vs = append(vs, x)
		}
		all = append(all, append(vs, id))
		id++
	}

	// q1
	sort.Sort(all)
	fmt.Println(all[0])

	// q2
	for i := 0; i < len(all); i++ {
		for j := i + 1; j < len(all); j++ {
			if collide(all[i], all[j]) {
				all[i][9] = -1
				all[j][9] = -1
			}
		}
	}

	sum := 0
	for _, x := range all {
		if x[9] == -1 {
			sum += 1
		}
	}
	fmt.Println(len(all)-sum, sum)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
