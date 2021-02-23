// ======= Y ======>
// |
// |
// X
// |
//
package main

import (
	"crypto/md5"
	"fmt"
)

type Status struct {
	x, y int
	path string
}

func doors(salt string, s Status) (ret []string) {
	hash := fmt.Sprintf("%x", md5.Sum([]byte(salt+s.path)))
	ds := []string{"U", "D", "L", "R"}
	for i, d := range ds {
		if hash[i] >= 'b' && hash[i] <= 'f' {
			ret = append(ret, d)
		}
	}
	return
}

func q1(salt string) string {
	var a, b []Status
	a = append(a, Status{0, 0, ""})
	cur := 0
	for cur < 1000 {

		if len(a) == 0 {
			break
		}

		for _, s := range a {
			if s.x == 3 && s.y == 3 {
				// the longest
				fmt.Println(len(s.path), s.path)
				continue
			}
			for _, d := range doors(salt, s) {
				switch d {
				case "U":
					if s.x != 0 {
						b = append(b, Status{s.x - 1, s.y, s.path + "U"})
					}
				case "D":
					if s.x != 3 {
						b = append(b, Status{s.x + 1, s.y, s.path + "D"})
					}
				case "L":
					if s.y != 0 {
						b = append(b, Status{s.x, s.y-1, s.path+"L"})
					}
				case "R":
					if s.y != 3 {
						b = append(b, Status{s.x, s.y+1, s.path+"R"})
					}
				}
			}
		}
		a, b = b, a
		b = nil
		cur ++
	}
	return ""
}

func main() {
    fmt.Println(q1("rrrbmfta"))
	// fmt.Println(q1("ihgpwlah"))
}
