// make it simpler
// Read the description !!!!!
// The 64th may not be the be 64th, it's just the 64th found with the smallest +1000 offset ~~~
// TODO it again
package main

import (
	"crypto/md5"
	"fmt"
	"strconv"
	"sort"
)

type A3 struct {
	a string
	k string
	i int
}

func parse(hash []byte) (a3 string, a5 map[string]bool) {
	a5 = make(map[string]bool)
	for i := 0; i < len(hash); i++ {
		if a3 == "" {
			if i+2 < len(hash) {
				if hash[i] == hash[i+1] && hash[i+1] == hash[i+2] {
					a3 = string(hash[i : i+3])
				}
			}
		}

		if i+4 < len(hash) {
			if hash[i] == hash[i+1] && hash[i+1] == hash[i+2] && hash[i+2] == hash[i+3] && hash[i+3] == hash[i+4] {
				a5[string(hash[i:i+3])] = true
			}
		}
	}
	return
}

func stretch(h string) string {
	for i := 0; i < 2016; i++ {
		h = fmt.Sprintf("%x", md5.Sum([]byte(h)))
	}
	return h
}

// sort
func q1(salt string) {
	var all []A3
	var sorts []int
	keys := make(map[int]string)
	i := 0

	for {

		// make sure we check the +1000 of the 64th keys
		if len(sorts) >= 64 && i > sorts[63] + 1000 {
			fmt.Println(sorts[63])
			fmt.Println(len(keys), keys[sorts[63]], keys)
			break
		}

		// q1
		// hash := fmt.Sprintf("%x", md5.Sum([]byte(salt+strconv.Itoa(i))))

		// q2
		hash := fmt.Sprintf("%x", md5.Sum([]byte(salt+strconv.Itoa(i))))
		hash = stretch(hash)

		a3, a5 := parse([]byte(hash))
		for p, _ := range a5 {
			for j := 0; j < len(all); j++ {

				if all[j].i+1000 < i {
					continue
				}

				if all[j].a == p {
					keys[all[j].i] = all[j].k
					sorts = append(sorts, all[j].i)
					sort.Ints(sorts)
				}
			}
		}
		all = append(all, A3{a3, hash, i})
		i++
	}
}

func main() {
	q1("abc")
	q1("ihaygndm")
}
