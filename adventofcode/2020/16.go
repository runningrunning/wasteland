// how to speed up, better ways?
// Just set those can not be other fields at the first
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func parse(f *os.File) (cond map[string][]int, mine []int, other [][]int) {
	input := bufio.NewScanner(f)
	status := 0
	cond = make(map[string][]int)

	for input.Scan() {
		text := input.Text()
		if len(text) != 0 {
			if text == "your ticket:" {
				status = 1
				continue
			} else if text == "nearby tickets:" {
				status = 2
				continue
			}
			switch status {
			case 0:
				fields := strings.Split(text, ":")
				values := make([]int, 4)
				fmt.Sscanf(fields[1], "%d-%d or %d-%d", &values[0], &values[1], &values[2], &values[3])
				cond[fields[0]] = values
			case 1, 2:
				fields := strings.Split(text, ",")
				values := make([]int, len(fields))
				for i, v := range fields {
					values[i], _ = strconv.Atoi(v)
				}

				if status == 1 {
					mine = values
				} else {
					other = append(other, values)
				}
			}
		}
	}

	return cond, mine, other
}

func q1(f *os.File) {
	cond, _, other := parse(f)
	sum := 0
	num := 0
	for _, vs := range other {
		for _, v := range vs {
			found := false
			for _, c := range cond {
				if (v >= c[0] && v <= c[1]) || (v >= c[2] && v <= c[3]) {
					found = true
					break
				}
			}

			if found {
				continue
			}
			sum += v
			num++
		}
	}
	fmt.Println(sum, num, len(other))
}

func try(cond map[string][]int, used map[string]bool, left [][]int, mine []int, match []string, c int, cache map[string]map[int]bool) bool {
	if len(mine) == c {
		// value := 1
		// for i, v := range match {
		// 	// if strings.HasPrefix(v, "departure") {
		// 	// 	value *= mine[i]
		// 	// }
		// }
		fmt.Println(match)
		return true
	} else {
		fmt.Println(match, c, len(mine))
		for i, v := range cond {
			if used[i] {
				continue
			}

			if t, ok := cache[i][c]; ok {
				if t {
					used[i] = true
					match[c] = i
					if try(cond, used, left, mine, match, c+1, cache) {
						return true
					}
					used[i] = false
				}
				continue
			}

			valid := true
			for _, t := range left {
				if !((t[c] >= v[0] && t[c] <= v[1]) || (t[c] >= v[2] && t[c] <= v[3])) {
					valid = false
					break
				}
			}

			cache[i][c] = valid

			if valid {
				used[i] = true
				match[c] = i
				if try(cond, used, left, mine, match, c+1, cache) {
					return true
				}
				used[i] = false
			}
		}
	}
	return false
}

func try1(cond map[string][]int, used map[string]bool, left [][]int, mine []int, match []string, c int, cache map[string]map[int]bool) bool {
	if len(mine) == c {
		// value := 1
		// for i, v := range match {
		// 	// if strings.HasPrefix(v, "departure") {
		// 	// 	value *= mine[i]
		// 	// }
		// }
		fmt.Println(match)
		return true
	} else {
		fmt.Println(match, c, len(mine))
		// fast check whther all of valid has been taken
		for i, _ := range cond {
			if used[i] {
				continue
			}

			found := false
			for m, n := range cache[i] {
				if !n || m < c {
					continue
				}
				found = true
				break
			}

			if !found {
				return false
			}
		}

		// do normal match
		for i, _ := range cond {
			if used[i] {
				continue
			}
			if cache[i][c] {
				used[i] = true
				match[c] = i
				if try1(cond, used, left, mine, match, c+1, cache) {
					return true
				}
				used[i] = false
			}
		}
	}
	return false
}

func try2(cond map[string][]int, used map[string]bool, left [][]int, mine []int, match []string, c int, cache map[string]map[int]bool) bool {
	if len(mine) == c {
		value := 1
		for i, v := range match {
			if strings.HasPrefix(v, "departure") {
				value *= mine[i]
			}
		}
		fmt.Println(match, value)
		return true
	} else {
		fmt.Println(match, c, len(mine))
		// do normal match
		for i, _ := range cond {
			if used[i] {
				continue
			}
			if cache[i][c] {
				used[i] = true
				match[c] = i
				if try2(cond, used, left, mine, match, c+1, cache) {
					return true
				}
				used[i] = false
			}
		}
	}
	return false
}

func q2(f *os.File) {
	cond, mine, other := parse(f)
	var left [][]int
	left = append(left, mine)
	for _, vs := range other {
		valid := true
		for _, v := range vs {
			found := false
			for _, c := range cond {
				if (v >= c[0] && v <= c[1]) || (v >= c[2] && v <= c[3]) {
					found = true
					break
				}
			}

			if found == false {
				valid = false
				break
			}
		}

		if valid {
			left = append(left, vs)
		}
	}

	fmt.Println(len(left))
	used := make(map[string]bool)
	match := make([]string, len(mine))
	cache := make(map[string]map[int]bool)
	for i, _ := range cond {
		cache[i] = make(map[int]bool)
	}
	try(cond, used, left, mine, match, 0, cache)
}

func q3(f *os.File) {
	cond, mine, other := parse(f)
	var left [][]int
	left = append(left, mine)
	for _, vs := range other {
		valid := true
		for _, v := range vs {
			found := false
			for _, c := range cond {
				if (v >= c[0] && v <= c[1]) || (v >= c[2] && v <= c[3]) {
					found = true
					break
				}
			}

			if found == false {
				valid = false
				break
			}
		}

		if valid {
			left = append(left, vs)
		}
	}

	fmt.Println(len(left))
	used := make(map[string]bool)
	match := make([]string, len(mine))
	cache := make(map[string]map[int]bool)

	nums := make(map[string]int)

	for i, c := range cond {
		cache[i] = make(map[int]bool)
		for j := 0; j < len(mine); j++ {
			valid := true
			for _, l := range left {
				if !((l[j] >= c[0] && l[j] <= c[1]) || (l[j] >= c[2] && l[j] <= c[3])) {
					valid = false
					break
				}
			}
			cache[i][j] = valid

			if cache[i][j] {
				nums[i]++
			}
		}
	}
	fmt.Println(nums)

	try1(cond, used, left, mine, match, 0, cache)
}

func q4(f *os.File) {
	cond, mine, other := parse(f)
	var left [][]int
	left = append(left, mine)
	for _, vs := range other {
		valid := true
		for _, v := range vs {
			found := false
			for _, c := range cond {
				if (v >= c[0] && v <= c[1]) || (v >= c[2] && v <= c[3]) {
					found = true
					break
				}
			}

			if found == false {
				valid = false
				break
			}
		}

		if valid {
			left = append(left, vs)
		}
	}

	fmt.Println(len(left))

	used := make(map[string]bool)
	match := make([]string, len(mine))
	cache := make(map[string]map[int]bool)

	nums := make(map[string]int)

	for i, c := range cond {
		cache[i] = make(map[int]bool)
		for j := 0; j < len(mine); j++ {
			valid := true
			for _, l := range left {
				if !((l[j] >= c[0] && l[j] <= c[1]) || (l[j] >= c[2] && l[j] <= c[3])) {
					valid = false
					break
				}
			}
			cache[i][j] = valid

			if cache[i][j] {
				nums[i]++
			}
		}
	}

	// reduce cache from 1 ~ n
	for {
		found := false

		fmt.Println(nums)

		for i, n := range nums {
			if n == 1 {
				found = true
				for t, v := range cache[i] {
					if v {
						for c, cs := range cache {
							if cs[t] {
								nums[c]--

								if c != i {
									cs[t] = false
								}
							}
						}
						break
					}
				}
				break
			}
		}

		if !found {
			break
		}
	}

	try2(cond, used, left, mine, match, 0, cache)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	// q3(f)
	q4(f)
}
