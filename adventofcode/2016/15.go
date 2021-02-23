package main

import (
	"bufio"
	"fmt"
	"os"
)

type Disk struct {
	id, length, position int
}

func parse(f *os.File) (ds []Disk) {
	input := bufio.NewScanner(f)

	for input.Scan() {
		d := Disk{}
		fmt.Sscanf(input.Text(), "Disc #%d has %d positions; at time=0, it is at position %d.", &d.id, &d.length, &d.position)
		ds = append(ds, d)
	}
	return
}

func q1(f *os.File) {
	ds := parse(f)
	ds = append(ds, Disk{7, 11, 0})

	i := 0
	for {
		found := true

		for _, d := range ds {
			if (i + d.id + d.position) % d.length != 0 {
				found = false
				break
			}
		}

		if found {
			break
		}

		i ++
	}

	fmt.Println(i)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
