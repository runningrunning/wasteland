// At each "player turn" not "each player" ~!!!
package main

import "fmt"

// mana, damage, heal, last (0 means instantly), edamge, earmour, emana
const sl = 5

var sp = [sl][]int{
	[]int{53, 4, 0, 0, 0, 0, 0},
	[]int{73, 2, 2, 0, 0, 0, 0},
	[]int{113, 0, 0, 6, 0, 7, 0},
	[]int{173, 0, 0, 6, 3, 0, 0},
	[]int{229, 0, 0, 5, 0, 0, 101},
}

// effect take 2 turns in a round !!!!
func mana(player bool, hp, ma, bhp, bat, used int, effect [sl]int, min *int) {

	if used > *min {
		return
	}

	// q2
	// if player {
	// 	hp -= 1
	// 	if hp <= 0 {
	// 		return
	// 	}
	// }

	ar := 0

	// effect
	for i := 0; i < sl; i++ {
		if effect[i] != 0 {
			effect[i] -= 1
			bhp -= sp[i][4]
			ar += sp[i][5]
			ma += sp[i][6]
		}
	}

	// win
	if bhp <= 0 {
		if used < *min {
			*min = used
		}
		return
	}

	if player {
		for i := 0; i < sl; i++ {
			if ma < sp[i][0] {
				continue
			}

			if sp[i][3] != 0 && effect[i] != 0 {
				continue
			}

			effect[i] = sp[i][3]
			mana(false, hp+sp[i][2], ma-sp[i][0], bhp-sp[i][1], bat, used+sp[i][0], effect, min)
			effect[i] = 0
		}
	} else {
		hp -= bat - ar
		if hp <= 0 {
			return
		}
		mana(true, hp, ma, bhp, bat, used, effect, min)
	}
}

func q1(hp, ar int) int {
	min := int((^uint(0)) >> 1)
	// effect is array, not slice
	effect := [sl]int{}
	mana(true, 50, 500, 51, 9, 0, effect, &min)
	return min
}

func main() {
	fmt.Println(q1(51, 9))
}
