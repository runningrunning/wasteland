// TODO: better solution, find the smallest and then do verify
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

func sum(in []int) (r int) {
	for _, n := range in {
		r += n
	}
	return r
}

func onethird(check bool, all []int, used []bool, need, cur, num, q, w int, min, minq *int) bool {
	if !check {
		if num > *min {
			return false
		}

		if q > *minq {
			return false
		}
	}

	if cur >= len(all) {
		if need == 0 {
			// check whether it's possible to divide another 1/3
			if !check && onethird(true, all, used, w, 0, 0, 0, w, min, minq) {
				if num < *min {
					*min = num
					*minq = q
				} else if num == *min {
					if q < *minq {
						*minq = q
					}
				}
			}
			return true
		}
		return false
	}

	if need < 0 {
		return false
	}

	without := onethird(check, all, used, need, cur+1, num, q, w, min, minq)

	if used[cur] {
		return without
	}

	// use current one
	used[cur] = true
	with := onethird(check, all, used, need-all[cur], cur+1, num+1, q*all[cur], w, min, minq)
	used[cur] = false
	return with || without
}

func half(onefourth bool, all []int, used []bool, need, cur, num, q, w int, min, minq *int) {
	if onefourth {
		if num > *min {
			return
		}

		if q > *minq {
			return
		}
	}

	if cur >= len(all) {
		if need == 0 {
			if !onefourth {
				half(true, all, used, w/2, 0, 0, 1, w, min, minq)
			} else {
				// try the current used
				if num < *min {
					*min = num
					*minq = q
				} else if num == *min {
					if q < *minq {
						*minq = q
					}
				}
				// try the not used, as 1 - 1/2 - 1/4 = 1/4
				tn := 0
				tq := 1
				for i, u := range used {
					if !u {
						tn++
						tq *= all[i]
					}
				}
				if tn < *min {
					*min = tn
					*minq = tq
				} else if tn == *min {
					if tq < *minq {
						*minq = tq
					}
				}
			}
		}
		return
	}
	if need < 0 {
		return
	}
	half(onefourth, all, used, need, cur+1, num, q, w, min, minq)
	if used[cur] {
		return
	}
	used[cur] = true
	half(onefourth, all, used, need-all[cur], cur+1, num+1, q*all[cur], w, min, minq)
	used[cur] = false
}

func q1(f *os.File) (int, int) {
	all := parse(f)
	used := make([]bool, len(all), len(all))
	min := len(all)
	minq := int((^uint(0)) >> 1)
	onethird(false, all, used, sum(all)/3, 0, 0, 1, sum(all)/3, &min, &minq)
	return min, minq
}

func q2(f *os.File) (int, int) {
	all := parse(f)
	used := make([]bool, len(all), len(all))
	min := len(all)
	minq := int((^uint(0)) >> 1)
	half(false, all, used, sum(all)/2, 0, 0, 1, sum(all)/2, &min, &minq)
	return min, minq
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	fmt.Println(q1(f))
	fmt.Println(q2(f))
}
