// It's fun ~~~
// something about matrix and transform
// positions changes and programs changes are different, they can be applied at the different
// steps
package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func parser(f *os.File, l int) ([]int, map[byte]byte) {
	f.Seek(0, 0)
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))

	positions := make([]int, l, l)
	programs := make(map[byte]byte)
	start := 0

	for i := 0; i < l; i++ {
		positions[i] = i
		programs[byte('a'+i)] = byte('a' + i)
	}

	for _, d := range strings.Split(input, ",") {
		switch d[0] {
		case 's':
			x, _ := strconv.Atoi(d[1:])
			x %= l
			start += l - x
		case 'x':
			ab := strings.Split(d[1:], "/")
			a, _ := strconv.Atoi(ab[0])
			b, _ := strconv.Atoi(ab[1])
			a = (a + start) % l
			b = (b + start) % l
			positions[a], positions[b] = positions[b], positions[a]
		case 'p':
			ab := d[1:]
			programs[ab[0]], programs[ab[2]] = programs[ab[2]], programs[ab[0]]
		}
	}

	real_positions := make([]int, l, l)
	for i := 0; i < l; i++ {
		real_positions[i] = positions[(start+i)%l]
	}
	return real_positions, programs
}

func apply(init string, l int, positions []int, programs map[byte]byte) string {
	if init == "" {
		for i := 0; i < l; i++ {
			init += string('a' + i)
		}
	}
	result := []byte(init)

	for i, p := range positions {
		result[i] = byte(init[int(p)])
	}

	// Need to revert 'b' => 'a' means 'a' will be replaced by 'b'
	real_programs := make(map[byte]byte)
	for i, p := range programs {
		real_programs[p] = i
	}

	for i, p := range result {
		if real_programs[p] != 0 {
			result[i] = real_programs[p]
		}
	}
	return string(result)
}

func combine_positions(a, b []int) []int {
	if a == nil {
		return b
	}

	if b == nil {
		return a
	}

	n := make([]int, len(a), len(a))

	for i := 0; i < len(a); i++ {
		n[i] = b[a[i]]
	}
	return n
}

func combine_programs(a, b map[byte]byte) map[byte]byte {
	if a == nil {
		return b
	}

	if b == nil {
		return a
	}
	n := make(map[byte]byte)

	// Must apply b at the first
	for f, t := range b {
		n[f] = a[t]
	}
	return n
}

func combined(f *os.File, l, t int) string {
	po, pr := parser(f, l)

	var pos [][]int
	var prs []map[byte]byte

	pos = append(pos, po)
	prs = append(prs, pr)

	s := 1

	for s <= t {
		s *= 2
		pos = append(pos, combine_positions(pos[len(pos)-1], pos[len(pos)-1]))
		prs = append(prs, combine_programs(prs[len(prs)-1], prs[len(prs)-1]))
	}

	var apo []int
	var apr map[byte]byte
	for i := 0; i < len(pos); i++ {
		if (t & (1 << i)) != 0 {
			apo = combine_positions(apo, pos[i])
			apr = combine_programs(apr, prs[i])
		}
	}
	return apply("", l, apo, apr)
}

func q1_2(f *os.File, l int) string {
	po, pr := parser(f, l)
	return apply("", l, po, pr)
}

func q1(f *os.File, l int, nop, onlyp bool, init string) string {
	f.Seek(0, 0)
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))
	r2p := make(map[byte]int)
	all := make([]byte, l, l)
	start := 0

	if init == "" {
		for i := 0; i < l; i++ {
			r2p[byte('a'+i)] = i
			all[i] = byte('a' + i)
		}
	} else {
		all = []byte(init)
		all = all[:l]
		for i := 0; i < l; i++ {
			r2p[all[i]] = i
		}
	}

	for _, d := range strings.Split(input, ",") {
		switch d[0] {
		case 's':
			if !onlyp {
				x, _ := strconv.Atoi(d[1:])
				x %= l
				start += l - x
			}
		case 'x':
			if !onlyp {
				ab := strings.Split(d[1:], "/")
				a, _ := strconv.Atoi(ab[0])
				b, _ := strconv.Atoi(ab[1])
				a = (a + start) % l
				b = (b + start) % l
				r2p[all[a]] = b
				r2p[all[b]] = a
				all[a], all[b] = all[b], all[a]
			}
		case 'p':
			if !nop {
				ab := d[1:]
				r2p[ab[0]], r2p[ab[2]] = r2p[ab[2]], r2p[ab[0]]
				all[r2p[ab[0]]] = ab[0]
				all[r2p[ab[2]]] = ab[2]
			}
		}
	}

	var r string

	for i := 0; i < l; i++ {
		r += string(all[(start+i)%l])
	}
	return r
}

func test(f *os.File, l int) {
	fmt.Println(q1(f, l, false, false, ""))
	fmt.Println(q1_2(f, l))

	fmt.Println("==================")
	for i := 2; i <= 1024; i += 2 {
		s1 := ""
		for j := 0; j < i; j++ {
			s1 = q1(f, l, false, false, s1)
		}

		// s2 := q2(f, l, i)
		s2 := combined(f, l, i)
		if s1 != s2 {
			fmt.Println(i, s1, s2)
		}
	}
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	fmt.Println(combined(f, 16, 1))
	fmt.Println(combined(f, 16, 1000000000))
}
