package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func q1(f *os.File, half bool) {
	raw, _ := ioutil.ReadAll(f)
	// fmt.Println(raw)
	if raw[len(raw)-1] == '\n' {
		raw = raw[:len(raw)-1]
	}
	// fmt.Println(raw)
	captcha := 0
	step := 1

	if half {
		step = len(raw) / 2;
	}

	for i, ch := range raw {
		if ch == raw[(i+step)%len(raw)] {
			captcha += int(ch - '0')
		}
	}

	fmt.Println(captcha)

}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f, false)
	f.Seek(0, 0)
	q1(f, true)
}
