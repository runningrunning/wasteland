package main

import (
	"fmt"
	"math/rand"
	"os"
	"tgpl/popcount"
	"time"
)

// Must seed the math/rand beforing use it or try crypto/rand
// https://stackoverflow.com/questions/39529364/go-rand-intn-same-number-value
func main() {
	rand.Seed(time.Now().UnixNano())
	input := rand.Uint64()
	fmt.Fprintf(os.Stdout, "%u: %b %d %d %d %d\n", input, input,
		popcount.PopCount(input), popcount.PopCountLoop(input),
		popcount.PopCountShift(input), popcount.PopCountOr(input))
}
