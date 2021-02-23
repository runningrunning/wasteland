package main

import (
	"fmt"
)

func output(in []string) {
	for _, l := range in {
		fmt.Println(l)
	}
	fmt.Println()
}

func countline(l string) int {
	sum := 0
	for _, c := range l {
		if c == '.' {
			sum ++
		}
	}
	return sum
}

func count(in []string) int {
	sum := 0

	for _, l := range in {
		sum += countline(l)
	}
	return sum
}

func line(l string) string {
	t := []byte(l)
	trap := func(x int) bool {
		if x < 0 || x >= len(l) {
			return false
		}
		return l[x] == '^'
	}

	for i := 0; i < len(l); i++ {
		if trap(i-1) != trap(i+1) {
			t[i] = '^'
		} else {
			t[i] = '.'
		}
	}
	return string(t)
}

func generate(in string, l int) (ret []string) {
	ret = append(ret, in)
	for i := 1; i < l; i++ {
		ret = append(ret, line(ret[len(ret)-1]))
	}
	return ret
}

func q2(in string, l int) {
	sum := countline(in)

	for i := 1; i < l; i ++ {
		in = line(in)
		sum += countline(in)
	}

	fmt.Println(sum)
}

func q1(in string, l int) {
	output(generate(in, l))
	fmt.Println(count(generate(in, l)))
}

func main() {
	q1("..^^.", 3)
	q1(".^^.^.^^^^", 10)
	q1(".^.^..^......^^^^^...^^^...^...^....^^.^...^.^^^^....^...^^.^^^...^^^^.^^.^.^^..^.^^^..^^^^^^.^^^..^", 40)
	q2(".^.^..^......^^^^^...^^^...^...^....^^.^...^.^^^^....^...^^.^^^...^^^^.^^.^.^^..^.^^^..^^^^^^.^^^..^", 400000)
}
