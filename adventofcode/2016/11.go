// BFS/DFS?
// Simple solution?
// Simple & Fast Code?
package main

import (
	"fmt"
)

var IDs = map[string]uint64{"promethium generator": 1 << 0,
	"promethium microchip": 1 << 1,
	"cobalt generator":     1 << 2,
	"cobalt microchip":     1 << 3,
	"curium generator":     1 << 4,
	"curium microchip":     1 << 5,
	"ruthenium generator":  1 << 6,
	"ruthenium microchip":  1 << 7,
	"plutonium generator":  1 << 8,
	"plutonium microchip":  1 << 9,
	"elerium generator":    1 << 10,
	"elerium  microchip":   1 << 11,
	"dilithium generator":  1 << 12,
	"dilithium microchip":  1 << 13,
}

var mask = uint64(1<<14) - 1

func chips(i uint64) bool {
	return i == uint64(1<<1) || i == uint64(1<<3) || i == uint64(1<<5) || i == uint64(1<<7) || i == uint64(1<<9) || i == uint64(1<<11) || i == uint64(1<<13)
}

func safe(i uint64) bool {
	hasGenerator := false
	for _, id := range IDs {
		if (i&id) != 0 && !chips(id) {
			hasGenerator = true
			break
		}
	}

	if !hasGenerator {
		return true
	}

	for _, id := range IDs {
		if (i&id) != 0 && chips(id) {
			if (i & (id >> 1)) == 0 {
				return false
			}
		}
	}
	return true
}

func status(f1, f2, f3, f4, e uint64) uint64 {
	return f4<<44 | f3<<30 | f2<<16 | f1<<2 | e
}

func next(cur uint64) (ret []uint64) {
	ce := cur & 3
	floors := make([]uint64, 4, 4)
	floors[0] = (cur >> 2) & mask
	floors[1] = (cur >> 16) & mask
	floors[2] = (cur >> 30) & mask
	floors[3] = (cur >> 44) & mask

	// fmt.Printf("%d %b %b %b %b\n", ce, floors[0], floors[1], floors[2], floors[3])

	var items []uint64
	for _, id := range IDs {
		if (floors[ce] & id) != 0 {
			items = append(items, id)
		}
	}

	for i := 0; i < len(items); i++ {
		if ce != 0 {
			floors[ce-1] |= items[i]
			floors[ce] &= ^items[i]
			if safe(floors[ce-1]) && safe(floors[ce]) {
				ret = append(ret, status(floors[0], floors[1], floors[2], floors[3], ce-1))
			}
			floors[ce] |= items[i]
			floors[ce-1] &= ^items[i]
		}

		if ce != 3 {
			floors[ce+1] |= items[i]
			floors[ce] &= ^items[i]
			if safe(floors[ce+1]) && safe(floors[ce]) {
				ret = append(ret, status(floors[0], floors[1], floors[2], floors[3], ce+1))
			}
			floors[ce] |= items[i]
			floors[ce+1] &= ^items[i]
		}

		for j := i + 1; j < len(items); j++ {

			if ce != 0 {
				floors[ce-1] |= items[i] | items[j]
				floors[ce] &= (^items[i]) & (^items[j])
				if safe(floors[ce-1]) && safe(floors[ce]) {
					ret = append(ret, status(floors[0], floors[1], floors[2], floors[3], ce-1))
				}
				floors[ce] |= items[i] | items[j]
				floors[ce-1] &= (^items[i]) & (^items[j])
			}

			if ce != 3 {
				floors[ce+1] |= items[i] | items[j]
				floors[ce] &= (^items[i]) & (^items[j])
				if safe(floors[ce+1]) && safe(floors[ce]) {
					ret = append(ret, status(floors[0], floors[1], floors[2], floors[3], ce+1))
				}
				floors[ce] |= items[i] | items[j]
				floors[ce+1] &= (^items[i]) & (^items[j])
			}
		}
	}
	return
}

func q1() int {

	// f1 := uint64((1 << 0) | (1 << 1))
	// f2 := uint64((1 << 2) | (1 << 4) | (1 << 6) | (1 << 8))
	// f3 := uint64((1 << 3) | (1 << 5) | (1 << 7) | (1 << 9))
	// end := status(0, 0, 0, (uint64(1)<<10)-1, 3)

	f1 := uint64((1 << 0) | (1 << 1) | (1 << 10) | (1 << 11) | (1 << 12) | (1 << 13))
	f2 := uint64((1 << 2) | (1 << 4) | (1 << 6) | (1 << 8))
	f3 := uint64((1 << 3) | (1 << 5) | (1 << 7) | (1 << 9))
	end := status(0, 0, 0, (uint64(1)<<14)-1, 3)

	// f1 := uint64((1<<1)|(1<<3))
	// f2 := uint64(1<<0)
	// f3 := uint64(1<<2)
	// end := status(0, 0, 0, (uint64(1)<<4)-1, 3)

	f4 := uint64(0)
	e := uint64(0)

	steps := make(map[uint64]bool)
	steps[status(f1, f2, f3, f4, e)] = true

	var a, b []uint64
	a = append(a, status(f1, f2, f3, f4, e))

	cur := 0
	for {
		for _, s := range a {
			if s == end {
				return cur
			}
			for _, nxt := range next(s) {

				if steps[nxt] == false {
					steps[nxt] = true
					b = append(b, nxt)
				}
			}
		}
		a, b = b, a
		b = nil
		cur++

		if len(a) == 0 {
			break
		}
	}
	return -1
}

func main() {
	fmt.Println(q1())
}
