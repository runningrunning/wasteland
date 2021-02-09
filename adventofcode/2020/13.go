package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func q1(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	lines := strings.Split(string(raw), "\n")
	earliest, _ := strconv.Atoi(lines[0])
	var times []int

	for _, x := range strings.Split(lines[1], ",") {
		if x == "x" {
			continue
		}
		n, _ := strconv.Atoi(x)
		times = append(times, n)
	}

	fmt.Println(earliest)
	fmt.Println(times)

	i := 0
	for {
		for _, x := range times {
			if ((i + earliest) % x) == 0 {
				fmt.Println(i * x)
				return
			}
		}
		i += 1
	}
}

func _gcd(x, y int) int {
	if y == 0 {
		return x
	}
	return _gcd(y, x%y)
}

func gcd(x, y int) int {
	if x >= y {
		return _gcd(x, y)
	}
	return _gcd(y, x)
}

func common(x, y int) int {
	return x * y / gcd(x, y)
}

func starter(x, y, d int) int {
	c := x
	for {
		if (c+d)%y == 0 {
			return c
		}
		c += x
	}
}

func q2(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	lines := strings.Split(string(raw), "\n")

	var times []int

	for _, x := range strings.Split(lines[1], ",") {
		n := 0
		if x != "x" {
			n, _ = strconv.Atoi(x)
		}
		times = append(times, n)
	}

	cmax := 0
	ci, cj := 0, 0

	for i := 0; i < len(times); i++ {
		if times[i] == 0 {
			continue
		}

		for j := i + 1; j < len(times); j++ {
			if times[j] == 0 {
				continue
			}

			cur := common(times[i], times[j])
			if cur > cmax {
				cmax = cur
				ci = i
				cj = j
			}
		}
	}

	// fmt.Println(times[ci], times[cj], cmax)

	start := starter(times[ci], times[cj], cj-ci) - ci
	for {
		found := true
		for i, x := range times {
			if x == 0 {
				continue
			}
			if (start+i)%x != 0 {
				found = false
				break
			}
		}

		if found {
			fmt.Println(start)
			break
		}
		start += cmax
	}
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
