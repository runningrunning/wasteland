package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func round(in []int, lengths []int, cur, skip int) (int, int) {
	len := len(in)
	reverse := func(in []int, s, e int) {
		for i, j := s, e; i < j; i, j = i+1, j-1 {
			in[i%len], in[j%len] = in[j%len], in[i%len]
		}
	}

	for _, l := range lengths {
		cur %= len
		reverse(in, cur, cur+l-1)
		cur += l + skip
		skip += 1
	}

	return cur, skip
}

func q1(f *os.File, len int) {
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))

	var lengths []int

	for _, l := range strings.Split(input, ",") {
		x, _ := strconv.Atoi(l)
		lengths = append(lengths, x)
	}

	numbers := make([]int, 0, len)

	for i := 0; i < len; i++ {
		numbers = append(numbers, i)
	}
	round(numbers, lengths, 0, 0)
	fmt.Println(numbers, numbers[0]*numbers[1])
}

func q2(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))
	lengths := make([]int, 0, len(input)+5)
	for _, c := range []byte(input) {
		lengths = append(lengths, int(c))
	}
	lengths = append(lengths, 17, 31, 73, 47, 23)
	numbers := make([]int, 0, 256)
	for i := 0; i < 256; i++ {
		numbers = append(numbers, i)
	}
	cur, skip := 0, 0
	for i := 0; i < 64; i++ {
		cur, skip = round(numbers, lengths, cur, skip)
	}

	for i := 0; i < 16; i ++ {
		x := 0
		for j := 0; j < 16; j ++ {
			x ^= numbers[i * 16 + j]
		}
		fmt.Printf("%x", x)
	}
	fmt.Println()
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f, 256)
	f.Seek(0, 0)
	q2(f)
}
