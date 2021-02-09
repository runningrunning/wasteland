// builtin.make
//
// Slice: The size specifies the length. The capacity of the slice is
// equal to its length. A second integer argument may be provided to
// specify a different capacity; it must be no smaller than the
// length. For example, make([]int, 0, 10) allocates an underlying array
// of size 10 and returns a slice of length 0 and capacity 10 that is
// backed by this underlying array.

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func contain(a []string, s string) bool {
	for _, x := range a {
		if x == s {
			return true
		}
	}
	return false
}

func intersection(a, b []string) []string {
	if a == nil {
		return b
	}

	if b == nil {
		return a
	}

	var m []string
	for _, x := range a {
		if contain(b, x) {
			m = append(m, x)
		}
	}
	return m
}

func union(a, b []string) []string {
	if a == nil {
		return b
	}

	if b == nil {
		return a
	}

	for _, x := range b {
		if !contain(a, x) {
			a = append(a, x)
		}
	}
	return a
}

func parser(f *os.File) (map[string][]string, []string) {
	// itoa = make(map[string][]string)
	var ins []string
	atoi := make(map[string][]string)
	input := bufio.NewScanner(f)
	for input.Scan() {
		var is, as []string
		t := input.Text()
		ls := strings.Split(t, "(contains ")
		ls[0] = strings.TrimSpace(ls[0])
		is = strings.Split(ls[0], " ")

		ins = append(ins, is...)

		if len(ls[1]) != 0 {
			// remove )
			ls[1] = ls[1][:len(ls[1])-1]
			ls[1] = strings.ReplaceAll(ls[1], ",", "")
			as = strings.Split(ls[1], " ")
		}

		for _, a := range as {
			atoi[a] = intersection(atoi[a], is)
		}
	}
	return atoi, ins
}

func q1(f *os.File) {
	// map[dairy:[mxmxvkd] fish:[mxmxvkd sqjhc] soy:[sqjhc fvjkl]]
	// [mxmxvkd kfcds sqjhc nhms trh fvjkl sbzzf mxmxvkd sqjhc fvjkl sqjhc mxmxvkd sbzzf]

	atoi, ins := parser(f)
	may := make(map[string]int)
	// no need to reduce to 1 to 1 atoi
	// just calculate to possible
	for _, is := range atoi {
		for _, i := range is {
			may[i]++
		}
	}
	sum := 0
	for _, x := range ins {
		if may[x] == 0 {
			sum++
		}
	}

	fmt.Println(sum)
}

func remove(old []string, x string) []string {
	for i, v := range old {
		if v == x {
			old[i], old[len(old)-1] = old[len(old)-1], old[i]
			return old[:len(old)-1]
		}
	}
	return old
}

func reduce(atoi map[string][]string) map[string]string {
	ret := make(map[string]string)

	for len(atoi) != 0 {
		for k, v := range atoi {
			if len(v) == 1 {
				ret[k] = v[0]
				for nk := range atoi {
					if nk == k {
						continue
					}
					atoi[nk] = remove(atoi[nk], v[0])
				}
			}
		}

		for k := range ret {
			delete(atoi, k)
		}
	}

	return ret
}

func q2(f *os.File) {
	atois, _ := parser(f)
	atoi := reduce(atois)
	ks := make([]string, 0, len(atoi))
	for k := range atoi {
		ks = append(ks, k)
	}
	sort.Strings(ks)
	is := make([]string, 0, len(atoi))
	for _, k := range ks {
		is = append(is, atoi[k])
	}
	fmt.Println(strings.Join(is, ","))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
