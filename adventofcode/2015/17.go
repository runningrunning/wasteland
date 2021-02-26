// TODO better way except enumeration all of the cases?
// Could be possible to solve in one turn? Yes
// slice is passed as reference, don't mess it
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func parse(f *os.File) (all []int) {
	f.Seek(0, 0)
	input := bufio.NewScanner(f)
	for input.Scan() {
		n, _ := strconv.Atoi(strings.TrimSpace(input.Text()))
		all = append(all, n)
	}
	return
}

func nums(all []int, cur, left int, cached []map[int]int) int {
	if cur >= len(all) {
		if left == 0 {
			return 1
		}
		return 0
	}

	if left < 0 {
		return 0
	}

	if _, ok := cached[cur][left]; !ok {
		cached[cur][left] = nums(all, cur+1, left, cached) +
			nums(all, cur+1, left-all[cur], cached)
	}

	return cached[cur][left]
}

// can not use cache this way, since it doesn't use the number of current used
func nums2(all []int, cur, left, used int) (t []int) {
	if cur >= len(all) {
		if left == 0 {
			t = make([]int, len(all), len(all))
			t[used-1] = 1
			return t
		}
		return nil
	}

	if left < 0 {
		return nil
	}

	w1 := nums2(all, cur+1, left, used)
	w2 := nums2(all, cur+1, left-all[cur], used+1)

	if w1 == nil {
		w1, w2 = w2, w1
	}

	if w2 != nil {
		for i := 0; i < len(all); i++ {
			w1[i] += w2[i]
		}
	}

	return w1
}

func nums3(all []int, cur, left, used int, cached []map[int]map[int][]int) []int {
	if cur >= len(all) {
		if left == 0 {
			t := make([]int, len(all), len(all))
			t[used-1] = 1
			return t
		}
		return nil
	}

	if left < 0 {
		return nil
	}

	if m, ok := cached[cur][left]; ok {
		if v, ok := m[used]; ok {
			return v
		}
	}

	w1 := nums3(all, cur+1, left, used, cached)
	w2 := nums3(all, cur+1, left-all[cur], used+1, cached)

	if cached[cur][left] == nil {
		cached[cur][left] = make(map[int][]int)
	}

	if w1 == nil && w2 == nil {
		cached[cur][left][used] = nil
	} else {

		// don't mess up the w1, w2 since it's passed as references
		t := make([]int, len(all), len(all))

		for i := 0; i < len(all); i ++ {
			if w1 != nil {
				t[i] += w1[i]
			}

			if w2 != nil {
				t[i] += w2[i]
			}
		}
		cached[cur][left][used] = t
	}
	return cached[cur][left][used]
}

func q1(f *os.File, t int) int {
	all := parse(f)
	cached := make([]map[int]int, len(all), len(all))

	for i := 0; i < len(all); i++ {
		cached[i] = make(map[int]int)
	}
	return nums(all, 0, t, cached)
}

func q2(f *os.File, t int) int {
	ret := nums2(parse(f), 0, t, 0)
	for i := 0; i < len(ret); i++ {
		if ret[i] != 0 {
			return ret[i]
		}
	}
	return -1
}

func q3(f *os.File, t int) int {
	all := parse(f)
	cached := make([]map[int]map[int][]int, len(all), len(all))

	for i := 0; i < len(all); i++ {
		cached[i] = make(map[int]map[int][]int)
	}
	ret := nums3(all, 0, t, 0, cached)
	for i := 0; i < len(ret); i++ {
		if ret[i] != 0 {
			return ret[i]
		}
	}
	return -1
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	fmt.Println(q1(f, 150))
	fmt.Println(q2(f, 150))
	fmt.Println(q3(f, 150))
}
