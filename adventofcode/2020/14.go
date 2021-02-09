package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func q1(f *os.File) {
	mask_0 := 0
	mask_1 := 0
	mem := make(map[int]int)
	input := bufio.NewScanner(f)
	for input.Scan() {
		if strings.HasPrefix(input.Text(), "mask") {
			var mask string
			mask_0, mask_1 = 0, 0
			fmt.Sscanf(input.Text(), "mask = %s", &mask)
			for i := len(mask) - 1; i >= 0; i-- {
				switch mask[i] {
				case '1':
					mask_1 |= 1 << (35 - i)
				case '0':
					mask_0 |= 1 << (35 - i)
				}
			}
			mask_0 = ^mask_0
		} else {
			var index, value int
			fmt.Sscanf(input.Text(), "mem[%d] = %d", &index, &value)
			mem[index] = (value | mask_1) & mask_0
		}
	}

	sum := 0
	for _, v := range mem {
		sum += v
	}

	fmt.Println(sum)
}

func q2(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	lines := strings.Split(string(raw), "\n")
	var mask_1 int
	// Used to clear the X bits
	var mask_0 int
	var float map[int]int
	mem := make(map[int]int)
	for _, line := range lines {
		if len(line) == 0 {
			break
		}
		if strings.HasPrefix(line, "mask") {
			var mask string
			var mask_x []int
			float = make(map[int]int)
			mask_0, mask_1 = 0, 0
			fmt.Sscanf(line, "mask = %s", &mask)
			for i := len(mask) - 1; i >= 0; i-- {
				switch mask[i] {
				case '1':
					mask_1 |= 1 << (35 - i)
				case 'X':
					mask_x = append(mask_x, 35-i)
					// Clear the X bits
					mask_0 |= 1 << (35 - i)
				}
			}
			if len(mask_x) != 0 {
				for n := (1 << len(mask_x)) - 1; n >= 0; n-- {
					f := 0
					t := n
					for i := 0; i < len(mask_x); i++ {
						if (t & 1) == 1 {
							f |= 1 << mask_x[i]
						}
						t >>= 1
					}
					float[f] = 1
				}
			}
			mask_0 = ^mask_0
		} else {
			var index, value int
			fmt.Sscanf(line, "mem[%d] = %d", &index, &value)
			mem[(index|mask_1) & mask_0] = value
			for i, _ := range float {
				mem[((index|mask_1) & mask_0)|i] = value
			}
		}
	}

	sum := 0
	for _, v := range mem {
		sum += v
	}

	fmt.Println(sum)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
