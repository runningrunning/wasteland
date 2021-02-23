// find the pattern
// It's A0B0A1B0A0B1A1B which is (A pattern) + (0 pattern) + (B pattern)
// reduce only take care the number of 0, if it's odd, the result is odd
package main

import (
	"fmt"
	"math"
)

func round(in string, l int, remove bool) string {
	for len(in) < l {
		in += "0"
		for i := len(in) - 2; i >= 0; i-- {
			if in[i] == '0' {
				in += "1"
			} else {
				in += "0"
			}
		}
	}
	if remove {
		return in[:l]
	}
	return in
}

func q1(i string, l int) string {
	s := round(i, l, true)

	t := l
	o := 1

	for (t & 1) == 0 {
		t >>= 1
		o <<= 1
	}

	var ret string

	// only count the number of '0'
	for k := 0; k < t; k++ {
		num0 := 0
		for j := k * o; j < k*o+o; j++ {
			if s[j] == '0' {
				num0++
			}
		}

		if (num0 & 1) == 1 {
			ret += "0"
		} else {
			ret += "1"
		}
	}

	return ret
}

func reverse(s string) string {
	t := []byte(s)
	for i := 0; i < len(s); i++ {
		if s[len(s)-1-i] == '0' {
			t[i] = '1'
		} else {
			t[i] = '0'
		}
	}
	return string(t)
}

func q2(i string, l int) string {
	num := int(math.Sqrt(float64(l)))

	s1 := round(i, num, false)
	r1 := reverse(s1)
	s0 := round("0", num, false)

	o := 1
	t := l

	for (t & 1) == 0 {
		o <<= 1
		t >>= 1
	}

	ret := ""
	for st := 0; st < t; st++ {
		num0 := 0
		for k := st * o; k < st*o+o; k++ {
			var c byte
			dk := k / (len(s1) + 1)
			ik := k % (len(s1) + 1)

			if ik < len(s1) {
				if dk&1 == 1 {
					c = r1[ik]
				} else {
					c = s1[ik]
				}
			} else {
				c = s0[dk]
			}

			if c == '0' {
				num0++
			}
		}

		if (num0 & 1) == 1 {
			ret += "0"
		} else {
			ret += "1"
		}
	}
	return ret
}

func main() {
	fmt.Println(q1("10000", 20))
	fmt.Println(q1("10111011111001111", 272))
	fmt.Println(q2("10111011111001111", 35651584))
}
