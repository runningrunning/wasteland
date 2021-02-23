package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Receive interface {
	Got(i int)
	ID(i int)
}

type Bot struct {
	id, value, number int
	high, low         Receive
}

type Output struct {
	id    int
	value []int
}

func (b *Bot) Got(i int) {
	if b.value == 0 {
		b.value = i
	} else {
		if i > b.value {
			b.high.Got(i)
			b.low.Got(b.value)
		} else {
			b.high.Got(b.value)
			b.low.Got(i)
		}

		if (i == 17 && b.value == 61) || (i == 61 && b.value == 17) {
			fmt.Println("It's ", b.id)
		}
		b.value = 0
	}
}

func (b *Bot) ID(i int) {
	b.id = i
}

func (o *Output) ID(i int) {
	o.id = i
}

func (o *Output) Got(i int) {
	o.value = append(o.value, i)
}

func toInt(x string) int {
	n, _ := strconv.Atoi(x)
	return n
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	bots := make(map[int]*Bot)
	outs := make(map[int]*Output)
	values := make(map[int]int)

	for input.Scan() {
		ws := strings.Split(input.Text(), " ")

		if ws[0] == "value" {
			values[toInt(ws[1])] = toInt(ws[5])
		} else {
			b1 := toInt(ws[1])
			o1 := toInt(ws[6])
			o2 := toInt(ws[11])
			var r1, r2 Receive

			if bots[b1] == nil {
				bots[b1] = new(Bot)
				bots[b1].ID(b1)
			}

			if ws[5] == "bot" {
				if bots[o1] == nil {
					bots[o1] = new(Bot)
				}
				r1 = bots[o1]
			} else {
				if outs[o1] == nil {
					outs[o1] = new(Output)
				}
				r1 = outs[o1]
			}

			if ws[10] == "bot" {
				if bots[o2] == nil {
					bots[o2] = new(Bot)
				}
				r2 = bots[o2]
			} else {
				if outs[o2] == nil {
					outs[o2] = new(Output)
				}
				r2 = outs[o2]
			}

			r1.ID(o1)
			r2.ID(o2)

			if ws[3] == "low" {
				bots[b1].low = r1
			} else {
				bots[b1].high = r1
			}

			if ws[8] == "low" {
				bots[b1].low = r2
			} else {
				bots[b1].high = r2
			}
		}
	}

	for v, b := range values {
		bots[b].Got(v)
	}

	for _, o := range outs {
		fmt.Println(o)
	}
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
