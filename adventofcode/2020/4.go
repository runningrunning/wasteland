package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func isValid(c []string) bool {
	if len(c) < 7 {
		return false
	}
	need := []string{"byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"}

	for _, n := range need {
		found := false
		for _, x := range c {
			if strings.HasPrefix(x, n) {
				found = true
				break
			}
		}

		if found == false {
			return false
		}
	}
	return true
}

func q1(f *os.File) {
	valid := 0
	input := bufio.NewScanner(f)

	current := []string{}

	for input.Scan() {
		if len(input.Text()) == 0 {
			if isValid(current) {
				valid++
			}
			current = []string{}
			continue
		}
		current = append(current, strings.Split(input.Text(), " ")...)
	}

	if isValid(current) {
		valid++
	}

	fmt.Println(valid)
}

func isValid2(c []string) bool {
	if len(c) < 7 {
		return false
	}
	need := []string{"byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"}

	for _, n := range need {
		found := false
		for _, x := range c {
			if strings.HasPrefix(x, n) {
				x = x[4:]
				switch n {
				case "byr:":
					if len(x) == 4 {
						if i, e := strconv.Atoi(x); e == nil {
							if i >= 1920 && i <= 2002 {
								found = true
							}
						}
					}
				case "iyr:":
					if len(x) == 4 {
						if i, e := strconv.Atoi(x); e == nil {
							if i >= 2010 && i <= 2020 {
								found = true
							}
						}
					}
				case "eyr:":
					if len(x) == 4 {
						if i, e := strconv.Atoi(x); e == nil {
							if i >= 2020 && i <= 2030 {
								found = true
							}
						}
					}
				case "hgt:":
					if strings.HasSuffix(x, "cm") {
						if len(x) == 5 {
							if i, e := strconv.Atoi(x[:3]); e == nil {
								if i >= 150 && i <= 193 {
									found = true
								}
							}
						}
					}
					if strings.HasSuffix(x, "in") {
						if len(x) == 4 {
							if i, e := strconv.Atoi(x[:2]); e == nil {
								if i >= 59 && i <= 76 {
									found = true
								}
							}
						}
					}
				case "hcl:":
					if len(x) == 7 && x[0] == '#' {
						ok := true
						for i := 1; i <= 6; i++ {
							if !((x[i] >= '0' && x[i] <= '9') || (x[i] >= 'a' && x[i] <= 'f')) {
								ok = false
							}
						}
						found = ok
					}
				case "ecl:":
					found = (x == "amb" || x == "blu" || x == "brn" || x == "gry" || x == "grn" || x == "hzl" || x == "oth")
				case "pid:":
					if len(x) == 9 {
						ok := true
						for i := 0; i < 9; i++ {
							if !(x[i] >= '0' && x[i] <= '9') {
								ok = false
							}
						}
						found = ok
					}
				}
				if found == true {
					break
				}
			}
		}
		if found == false {
			return false
		}
	}
	return true
}

func q2(f *os.File) {
	valid := 0
	input := bufio.NewScanner(f)

	current := []string{}

	for input.Scan() {
		if len(input.Text()) == 0 {
			if isValid2(current) {
				valid++
			}
			current = []string{}
			continue
		}
		current = append(current, strings.Split(input.Text(), " ")...)
	}

	if isValid2(current) {
		valid++
	}

	fmt.Println(valid)
}

func main() {
	f, _ := os.Open(os.Args[1:][0])
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Close()
}
