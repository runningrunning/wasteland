package main

import (
	"bufio"
	"crypto/sha256"
	"crypto/sha512"
	"flag"
	"fmt"
	"log"
	"os"
)

var f = flag.String("format", "", "SHA format, by default it's SHA256")

func main() {
	flag.Parse()
	args := flag.Args()

	// https://utcc.utoronto.ca/~cks/space/blog/programming/GoUnaddressableSlice

	// invalid operation sha256.Sum256(in)[0:] (slice of unaddressable value)
	// sum := func(in []byte) []byte { return sha256.Sum256(in)[0:]}

	// The careful technical version is in the Go specification in Address operators,
	// but the hand waving summary version is that most anonymous values are not
	// addressable (one big exception is composite literals). Here the return value
	// of sha1.Sum() is anonymous, because we're immediately slicing it.
	sum := func(in []byte) []byte { r := sha256.Sum256(in); return r[0:] }

	switch *f {
	case "256":
		sum = func(in []byte) []byte { r := sha256.Sum256(in); return r[0:] }
	case "384":
		sum = func(in []byte) []byte { r := sha512.Sum384(in); return r[0:] }
	case "512":
		sum = func(in []byte) []byte { r := sha512.Sum512(in); return r[0:] }
	default:
		*f = "256"
	}

	if len(args) == 0 {
		scanner := bufio.NewScanner(os.Stdin)
		for scanner.Scan() {
			v := scanner.Text()
			fmt.Fprintf(os.Stdout, "%v SUM%s => %x\n", v, *f, sum([]byte(v)))
		}

		if err := scanner.Err(); err != nil {
			log.Println(err)
		}
	} else {
		for _, v := range args {
			fmt.Fprintf(os.Stdout, "%v SUM%s => %x\n", v, *f, sum([]byte(v)))
		}
	}
}
