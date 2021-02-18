package main

import (
	"bufio"
	"fmt"
	"os"
)

func q1(f *os.File, times int) {
	ground := make(map[int]map[int]bool)

	ofX := 10000
	ofY := 10000

	burst := 0

	infected := func(m map[int]map[int]bool, x, y int) {
		if m[x] == nil {
			m[x] = make(map[int]bool)
		}
		m[x][y] = true
	}

	clean := func(m map[int]map[int]bool, x, y int) {
		if m[x] == nil {
			return
		}
		m[x][y] = false
	}

	check := func(m map[int]map[int]bool, x, y int) bool {
		if m[x] == nil {
			return false
		}
		return m[x][y]
	}

	input := bufio.NewScanner(f)

	x, y, r := 0, 0, 0
	for input.Scan() {
		y = len(input.Text())
		for w, c := range input.Text() {
			if c == '#' {
				infected(ground, ofX+r, ofY+w)
			}
		}
		r += 1
	}

	fmt.Println(x, y, r)
	dx, dy := -1, 0
	x = ofX + r/2
	y = ofY + y/2

	fmt.Println(x, y)

	left := func() {
		if dx == -1 {
			dx, dy = 0, -1
		} else if dx == 1 {
			dx, dy = 0, 1
		} else if dy == -1 {
			dx, dy = 1, 0
		} else if dy == 1 {
			dx, dy = -1, 0
		}
	}

	right := func() {
		if dx == -1 {
			dx, dy = 0, 1
		} else if dx == 1 {
			dx, dy = 0, -1
		} else if dy == -1 {
			dx, dy = -1, 0
		} else if dy == 1 {
			dx, dy = 1, 0
		}
	}

	forward := func() {
		x += dx
		y += dy
	}

	for i := 0; i < times; i++ {
		if check(ground, x, y) {
			right()
			clean(ground, x, y)
		} else {
			left()
			burst ++
			infected(ground, x, y)
		}
		forward()
	}
	fmt.Println(burst)
}

func q2(f *os.File, times int) {
	// Clean 0, Weakened 1, Infected 2, Flagged 3
	ground := make(map[int]map[int]int)

	ofX := 10000
	ofY := 10000

	burst := 0

	infected := func(m map[int]map[int]int, x, y int, force bool) {
		if m[x] == nil {
			m[x] = make(map[int]int)
		}
		if force {
			m[x][y] = 2
		} else {
			// 0->1, 1->2
			m[x][y] = (m[x][y] + 1) % 4
		}
	}

	clean := func(m map[int]map[int]int, x, y int) {
		if m[x] == nil {
			return
		}
		// 2->3, 3->0
		m[x][y] = (m[x][y] + 1) % 4
	}

	check := func(m map[int]map[int]int, x, y int) int {
		if m[x] == nil {
			return 0
		}
		return m[x][y]
	}

	input := bufio.NewScanner(f)

	x, y, r := 0, 0, 0
	for input.Scan() {
		y = len(input.Text())
		for w, c := range input.Text() {
			if c == '#' {
				infected(ground, ofX+r, ofY+w, true)
			}
		}
		r += 1
	}

	fmt.Println(x, y, r)
	dx, dy := -1, 0
	x = ofX + r/2
	y = ofY + y/2

	fmt.Println(x, y)

	left := func() {
		if dx == -1 {
			dx, dy = 0, -1
		} else if dx == 1 {
			dx, dy = 0, 1
		} else if dy == -1 {
			dx, dy = 1, 0
		} else if dy == 1 {
			dx, dy = -1, 0
		}
	}

	right := func() {
		if dx == -1 {
			dx, dy = 0, 1
		} else if dx == 1 {
			dx, dy = 0, -1
		} else if dy == -1 {
			dx, dy = -1, 0
		} else if dy == 1 {
			dx, dy = 1, 0
		}
	}

	reverse := func() {
		dx = -dx
		dy = -dy
	}

	forward := func() {
		x += dx
		y += dy
	}

	for i := 0; i < times; i++ {
		switch (check(ground, x, y)) {
		case 0:
			left()
			infected(ground, x, y, false)
		case 1:
			burst += 1
			infected(ground, x, y, false)
		case 2:
			right()
			clean(ground, x, y)
		case 3:
			reverse()
			clean(ground, x, y)
		}
		forward()
	}

	fmt.Println(burst)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f, 10000)
	f.Seek(0, 0)
	q2(f, 10000000)
}
