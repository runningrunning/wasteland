package main

import (
	"fmt"
	"os"
)

func round(in []byte) (r []byte) {
	p := in[0]
	n := 1

	append := func(n int, p byte) {
		if n > 10 {
			fmt.Errorf("Something wrong here.\n")
			os.Exit(1)
		}
		r = append(r, byte(n+'0'))
		r = append(r, p)
	}

	for i := 1; i < len(in); i++ {
		if in[i] == p {
			n++
		} else {
			append(n, p)
			p = in[i]
			n = 1
		}
	}
	append(n, p)

	return
}

func q1(s string, t int) {
	for i := 0; i < t; i++ {
		// fmt.Printf("%s => ", s)
		s = string(round([]byte(s)))
		// fmt.Printf("%s %d\n", s, len(s))
	}
	fmt.Printf("%d\n", len(s))
}

func main() {
	q1("1", 1)
	q1("11", 1)
	q1("21", 1)
	q1("1211", 1)
	q1("111221", 1)

	q1("1113222113", 50);

}
