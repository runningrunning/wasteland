// be careful about how to calculate the point
package main

import (
	"fmt"
)

var ws = [][]int{
	[]int{8, 4, 0},
	[]int{10, 5, 0},
	[]int{25, 6, 0},
	[]int{40, 7, 0},
	[]int{74, 8, 0},
}

var as = [][]int{
	[]int{13, 0, 1},
	[]int{31, 0, 2},
	[]int{53, 0, 3},
	[]int{75, 0, 4},
	[]int{102, 0, 5},
}

var rs = [][]int{
	[]int{25, 1, 0},
	[]int{50, 2, 0},
	[]int{100, 3, 0},
	[]int{20, 0, 1},
	[]int{40, 0, 2},
	[]int{80, 0, 3},
}

func win(php, pda, par, hp, da, ar int) bool {

	pda -= ar
	da -= par

	if pda <= 0 {
		pda = 1
	}

	if da <= 0 {
		da = 1
	}

	// how many turns can I/Boss get
	d := (hp + pda - 1) / pda
	pd := (php + da - 1) / da
	return pd >= d
}

func q1(hp, da, ar int) (int, int) {
	win_min := -1
	lost_max := -1
	// weapon is mandatory
	max := len(ws) * (len(as) + 1) * (len(rs) + 1) * (len(rs) + 1)
	for t := 0; t < max; t++ {
		i := t
		wi := i % len(ws)
		i /= len(ws)
		ai := i % (len(as) + 1)
		i /= len(as) + 1
		r1 := i % (len(rs) + 1)
		i /= len(rs) + 1
		r2 := i
		// Can choose none of rings
		if r1 == r2 && r2 != len(rs) {
			continue
		}
		cost, php, pda, par := ws[wi][0], 100, ws[wi][1], 0

		if ai != len(as) {
			cost += as[ai][0]
			par += as[ai][2]
		}

		if r1 != len(rs) {
			cost += rs[r1][0]
			pda += rs[r1][1]
			par += rs[r1][2]
		}

		if r2 != len(rs) {
			cost += rs[r2][0]
			pda += rs[r2][1]
			par += rs[r2][2]
		}

		if win(php, pda, par, hp, da, ar) {
			if win_min == -1 {
				win_min = cost
			} else if win_min > cost {
				win_min = cost
			}
		} else {
			if lost_max < cost {
				lost_max = cost
			}
		}
	}
	return win_min, lost_max
}

func main() {
	fmt.Println(q1(104, 8, 1))
}
