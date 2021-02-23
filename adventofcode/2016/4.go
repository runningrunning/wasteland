package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func valid(name, sector, checksum string) int {
	times := make(map[rune]int)

	for _, c := range name {
		if c != '-' {
			times[c]++
		}
	}

	score := make([]int, 26, 26)

	for i := 'a'; i <= 'z'; i++ {
		offset := int(i - 'a')
		score[offset] = times[i]*1024 + 25 - offset
	}
	sort.Ints(score)

	for i := 0; i < len(checksum); i++ {
		should := byte(25 - (score[25-i] & 0xff) + 'a')

		if should != checksum[i] {
			return 0
		}
	}

	x, _ := strconv.Atoi(sector)

	return x
}

func decode(name, sector string) string {
	x, _ := strconv.Atoi(sector)
	x %= 26

	var new_name string

	for _, c := range name {
		if c == '-' {
			new_name += " "
		} else {
			new_name += string(((int(c - 'a') + x)%26) + 'a')
		}
	}
	return new_name
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)
	sum := 0

	for input.Scan() {
		var name, sector, checksum string

		i := 0
		text := input.Text()

		for !(text[i] >= '0' && text[i] <= '9') {
			name += string(text[i])
			i++
		}

		for text[i] != '[' {
			sector += string(text[i])
			i++
		}

		// skip '['
		i++

		for text[i] != ']' {
			checksum += string(text[i])
			i++
		}

		score := valid(name, sector, checksum)

		if score != 0 {
			sum += score
			real_name := decode(name, sector)

			if strings.Contains(real_name, "north") {
				fmt.Println(real_name, sector)
			}
		}
	}
	fmt.Println(sum)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
