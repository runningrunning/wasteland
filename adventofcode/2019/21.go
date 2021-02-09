// case 1:
// case 2:
// doesn't mean fallthrough !!!!

// Q23 simulate the halt and also use go concurrent&channel
// TODO Solve Q23 by using concurrent and channel

package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

type input func() int
type output func(int)

func read(f *os.File) []int {
	raw, _ := ioutil.ReadAll(f)
	lines := strings.Split(string(raw), "\n")

	var code []int

	for _, c := range strings.Split(lines[0], ",") {
		n, _ := strconv.Atoi(c)
		code = append(code, n)
	}
	return code
}

func parameters(code []int, ip, l, base int, last_output bool) []int {
	op := code[ip]
	ret := make([]int, l)
	mode := 100

	for i := 0; i < l; i++ {
		switch (op / mode) % 10 {
		case 0:
			// last output will be always position mode
			// and it's used outside of this
			// so just assign ret[i] with the address
			if (i == l-1) && last_output {
				ret[i] = code[ip+1+i]
			} else {
				ret[i] = code[code[ip+1+i]]
			}
		case 1:
			if (i == l-1) && last_output {
				fmt.Println("Error, immediately mode should not used for output.")
			}
			ret[i] = code[ip+1+i]
		case 2:
			// last output will be always position mode
			// and it's used outside of this
			// so just assign ret[i] with the address
			if (i == l-1) && last_output {
				ret[i] = base + code[ip+1+i]
			} else {
				ret[i] = code[base+code[ip+1+i]]
			}
		}
		mode *= 10
	}

	return ret
}

func run(code []int, in input, out output, e *ENV, times int) bool {
	t := 0
	ip := 0
	base := 0

	if e != nil {
		ip = e.ip
		base = e.base
	}

	for ip < len(code) {
		halt := false

		if times != -1 && t >= times {
			e.ip = ip
			e.base = base
			return false
		}

		op := code[ip] % 100
		switch op {
		case 1, 2:
			ps := parameters(code, ip, 3, base, true)
			if op == 1 {
				code[ps[2]] = ps[0] + ps[1]
			} else {
				code[ps[2]] = ps[0] * ps[1]
			}
			ip += 4
		case 3:
			ps := parameters(code, ip, 1, base, true)
			code[ps[0]] = in()
			ip += 2
		case 4: // mode
			ps := parameters(code, ip, 1, base, false)
			out(ps[0])
			ip += 2
		case 5, 6: // mode
			ps := parameters(code, ip, 2, base, false)
			if (op == 5) == (ps[0] != 0) {
				ip = ps[1]
			} else {
				ip += 3
			}
		case 7, 8:
			ps := parameters(code, ip, 3, base, true)
			if op == 7 {
				if ps[0] < ps[1] {
					code[ps[2]] = 1
				} else {
					code[ps[2]] = 0
				}
			} else {
				if ps[0] == ps[1] {
					code[ps[2]] = 1
				} else {
					code[ps[2]] = 0
				}
			}
			ip += 4
		case 9:
			ps := parameters(code, ip, 1, base, false)
			base += ps[0]
			ip += 2
		case 99:
			halt = true
		}

		if halt {
			break
		}
		t++
	}
	return true
}

func run2(code []int, n, v int) int {
	// clone
	clone := make([]int, len(code))
	copy(clone, code)

	clone[1] = n
	clone[2] = v
	run(clone, nil, nil, nil, -1)

	return clone[0]
}

func q2(f *os.File) {
	code := read(f)
	fmt.Println(run2(code, 12, 2))

	for n := 0; n < 100; n++ {
		for v := 0; v < 100; v++ {
			if run2(code, n, v) == 19690720 {
				fmt.Println(n*100 + v)
				return
			}
		}
	}
}

func run5(code []int) []int {
	var o []int
	clone := make([]int, len(code))
	copy(clone, code)
	run(clone, func() int { return 1 },
		func(i int) { o = append(o, i) }, nil, -1)
	copy(clone, code)
	run(clone, func() int { return 5 },
		func(i int) { o = append(o, i) }, nil, -1)
	return o
}

func q5(f *os.File) {
	code := read(f)
	fmt.Println(run5(code))
}

func q9(f *os.File) {
	var o []int
	code := read(f)
	memory := make([]int, 100000)
	copy(memory, code)
	run(memory, func() int { return 1 },
		func(i int) { o = append(o, i) }, nil, -1)
	memory = make([]int, 100000)
	copy(memory, code)
	run(memory, func() int { return 2 },
		func(i int) { o = append(o, i) }, nil, -1)
	fmt.Println(o)
}

func q21(f *os.File) {
	var o []int
	ii := 0

	// i := []byte( "NOT A J\n" +
	// 	"NOT B T\n" +
	// 	"OR T J\n" +
	// 	"NOT C T\n" +
	// 	"OR T J\n" +
	// 	"AND D J\n" +
	// 	"WALK\n")

	// Remember to clear the T by using NOT E T; AND E T; then OR E T OR H T, AND T J
	i := []byte("NOT A J\n" +
		"NOT B T\n" +
		"OR T J\n" +
		"NOT C T\n" +
		"OR T J\n" +
		"AND D J\n" +
		"NOT E T\n" +
		"AND E T\n" +
		"OR E T\n" +
		"OR H T\n" +
		"AND T J\n" +
		"RUN\n")

	code := read(f)
	memory := make([]int, 100000)
	copy(memory, code)
	run(memory, func() int {
		in := int(i[ii])
		ii++
		return in
	}, func(i int) { o = append(o, i) }, nil, -1)

	for _, oi := range o {
		fmt.Printf("%c", byte(oi))
	}
	fmt.Println("")
	fmt.Println(o)
}

type ENV struct {
	ip   int
	base int
}

// multiple process code
// simulate halt
type PC struct {
	e    ENV
	in   []int
	out  []int
	code []int
}

func q23(f *os.File) {
	code := read(f)

	nat := [...]int{0, 0}
	var nat_packets [][2]int
	network := make([]*PC, 0, 50)

	has_nat := false

	for i := 0; i < 50; i++ {
		n := PC{}
		n.e = ENV{0, 0}
		n.in = []int{i}
		n.out = []int{}
		memory := make([]int, 100000)
		copy(memory, code)
		n.code = memory
		network = append(network, &n)
	}

	step := 100
	for {
		empty := true

		for i := 0; i < 50; i++ {
			n := network[i]
			for len(n.out) >= 3 {
				empty = false
				if n.out[0] == 255 {
					nat[0] = n.out[1]
					nat[1] = n.out[2]
					has_nat = true
				} else {
					network[n.out[0]].in = append(network[n.out[0]].in, n.out[1:3]...)
				}
				n.out = n.out[3:]
			}

			// check incoming queue as it may not do input/output in this steps
			if len(n.in) != 0 {
				empty = false
			}

			run(n.code, func() int {
				if len(n.in) == 0 {
					return -1
				}
				empty = false
				t := n.in[0]
				n.in = n.in[1:]
				return t
			}, func(i int) {
				empty = false
				n.out = append(n.out, i)
			}, &n.e, step)
		}

		if empty && has_nat {
			if len(nat_packets) != 0 {
				if nat[1] == nat_packets[len(nat_packets)-1][1] {
					fmt.Println("====================================== Y is ", nat[1])
					return
				}
			}
			nat_packets = append(nat_packets, nat)
			network[0].in = append(network[0].in, nat[0], nat[1])
		}
	}
}

func read_input() []byte {
	read := bufio.NewReader(os.Stdin)
	fmt.Print("Enter Text:")
	text, _ := read.ReadString('\n')
	return []byte(text)
}

func random_input(in int) (step [][]byte) {
	items := []string {
		"whirled peas\n",
		"bowl of rice\n",
		"mutex\n",
		"astronaut ice cream\n",
		"ornament\n",
		"tambourine\n",
		"mug\n",
		"easter egg\n",
	}

	// drop every thing
	for _, i := range items {
		step = append(step, []byte("drop " + i))
	}

	for i := 0; i < 8; i ++ {
		if (in & (1 << i)) != 0 {
			step = append(step, []byte("take " + items[i]))
		}
	}
	step = append(step, []byte("inv\n"))
	step = append(step, []byte("west\n"))
	return step
}

func q25(f *os.File) {
	code := read(f)
	memory := make([]int, 100000)
	copy(memory, code)

	saved := [][]byte {
		[]byte("west\n"),
		[]byte("take whirled peas\n"),
		[]byte("east\n"),
		[]byte("south\n"),
		[]byte("west\n"),
		[]byte("take bowl of rice\n"),
		[]byte("east\n"),
		[]byte("east\n"),
		[]byte("take mutex\n"),
		[]byte("east\n"),
		[]byte("take astronaut ice cream\n"),
		[]byte("east\n"),
		[]byte("take ornament\n"),
		[]byte("east\n"),
		[]byte("west\n"),
		[]byte("west\n"),
		[]byte("south\n"),
		[]byte("take tambourine\n"),
		[]byte("north\n"),
		[]byte("west\n"),
		[]byte("south\n"),
		[]byte("east\n"),
		[]byte("take mug\n"),
		[]byte("west\n"),
		[]byte("south\n"),
		[]byte("west\n"),
		[]byte("south\n"),
		[]byte("take easter egg\n"),
		[]byte("west\n"),
		[]byte("west\n"),
	}

	var input []byte
	var output []byte

	tries := (1 << 8) - 1
	run(memory, func()int {
		if input == nil || len(input) == 0 {
			if len(saved) != 0 {
				input = saved[0]
				saved = saved[1:]
			} else {
				if strings.Index(string(output), "Alert") == -1 {
					input = read_input()
				} else {
					if tries != 0 {
						output = nil
						saved = random_input(tries)
						input = saved[0]
						saved = saved[1:]
						tries -= 1
					} else {
						input = read_input()
					}
				}
			}
		}
		t := int(input[0])
		input = input[1:]
		return t
	}, func (i int) {
		output = append(output, byte(i))
		fmt.Printf("%c", byte(i))
	}, nil,  -1)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	// q2(f)
	// q5(f)
	// q9(f)
	// q21(f)
	// q23(f)
	q25(f)
}
