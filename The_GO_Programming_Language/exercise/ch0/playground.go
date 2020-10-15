/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
	"fmt"
	"math"
	"reflect"
	"strings"
    "strconv"
)

type test struct {
	Sv string
	Iv int
	Fv float64
	hv string
}

type TestInterface interface {
	Test() string
}

func (t test) Test() string {
	return "test"
}

type TestPtrInterface interface {
	TestPtr() string
}

func (t *test) TestPtr() string {
	return "testPtr"
}

func main() {
	newline := '\n'
	unicode := '国'
	fmt.Printf("%d %[1]q %[1]c\n", newline)
	fmt.Printf("%d %[1]q %[1]c\n", unicode)

	var z float64
	fmt.Println(z, -z, 1/z, -1/z, z/z)

	nan := math.NaN()
	fmt.Println(nan == nan, nan < nan, nan > nan)

	s := test{Sv: "test"}
	fmt.Println("Test reflect\n")
	fmt.Println(reflect.TypeOf(s))
	fmt.Println(reflect.TypeOf(s).Kind() == reflect.Struct)
	fmt.Println(reflect.ValueOf(s))
	fmt.Println(reflect.ValueOf(s).NumField())

	for i := 0; i < reflect.ValueOf(s).NumField(); i++ {
		k := reflect.TypeOf(s).Field(i)
		v := reflect.ValueOf(s).Field(i)
		fmt.Println(k, v, v.Type())
	}
	fmt.Println(s)

	// s.Iv = 1000

	// fmt.Println(reflect.ValueOf(s).FieldByName("Iv"))
	fmt.Println(reflect.ValueOf(s).FieldByName("Sv"))
	// reflect.ValueOf(s).FieldByName("Sv").SetString("xxx")
	// reflect.ValueOf(s).FieldByName("Iv").SetInt(500)
	// reflect.ValueOf(s).FieldByName("Fv").SetFloat(500.0)
	fmt.Println(s)

	// s_ := reflect.New(reflect.TypeOf(s)).Elem()
	// s_ := reflect.New(reflect.Indirect(reflect.ValueOf(s)).Type()).Elem()
	s_ := reflect.ValueOf(&s).Elem()

	// panic: reflect: reflect.Value.SetString using value obtained using unexported field
	// sv_ := s_.FieldByName("hv")

	t_ := reflect.TypeOf(&s).Elem()
    fmt.Printf("s_ %v t_ %v s_.Type() %v.\n", s_, t_, s_.Type())

	i_ := reflect.TypeOf((*TestInterface)(nil)).Elem()
	if t_.Implements(i_) {
		fmt.Printf("%v implement %v.\n", t_, i_)
	} else {
		fmt.Printf("%v NOT implement %v.\n", t_, i_)
	}

	p_ := reflect.TypeOf((*TestPtrInterface)(nil)).Elem()
	if reflect.PtrTo(t_).Implements(p_) {
		fmt.Printf("%v implement %v.\n", reflect.PtrTo(t_), p_)
	} else {
		fmt.Printf("%v NOT implement %v.\n", reflect.PtrTo(t_), p_)
	}

	if m := reflect.ValueOf(s).MethodByName("Test"); m.IsValid() {
		fmt.Printf("Call %v is %v.\n", m, m.Call(nil))
	}

	if m := reflect.ValueOf(&s).MethodByName("Test"); m.IsValid() {
		fmt.Printf("Call %v is %v.\n", m, m.Call(nil))
	}

	// Will not be called, since S -> *S is fine, but not *S -> S
	if m := reflect.ValueOf(s).MethodByName("TestPtr"); m.IsValid() {
		fmt.Printf("Call %v is %v.\n", m, m.Call(nil))
	}

	if m := reflect.ValueOf(&s).MethodByName("TestPtr"); !m.IsValid() {
		fmt.Printf("Call %v is %v.\n", m, m.Call(nil))
	}

	sv_ := s_.FieldByName("Sv")
	sv_.SetString("xxx")
	fmt.Println(s)

	fmt.Printf("%s Title %s.\n", "title", strings.Title("title"))
	fmt.Printf("%s Title %s.\n", "TITLE", strings.Title("TITLE"))

    if !false {

        s := "0xddd"
        i, _ := strconv.ParseInt(s, 16, 0)
        fmt.Printf("%s %d.\n", s, i)

        i, _ = strconv.ParseInt(s, 0, 0)
        fmt.Printf("%s %d.\n", s, i)

        s = "0XDDD"
        i, _ = strconv.ParseInt(s, 0, 0)
        fmt.Printf("%s %d.\n", s, i)

        i, _ = strconv.ParseInt(s, 16, 0)
        fmt.Printf("%s %d.\n", s, i)

        s = "0XFFFFFFFD"
        ui, _ := strconv.ParseUint(s, 16, 0)
        fmt.Printf("%s %d.\n", s, ui)

        ui, _ = strconv.ParseUint(s, 0, 0)
        fmt.Printf("%s %d.\n", s, ui)

        ui, _ = strconv.ParseUint(s, 0, 32)
        fmt.Printf("%s %d.\n", s, ui)

        i, _ = strconv.ParseInt(s, 0, 32)
        fmt.Printf("%s %d.\n", s, i)

        s = "-83"

        i, _ = strconv.ParseInt(s, 0, 32)
        fmt.Printf("%s %d.\n", s, i)

        ui, _ = strconv.ParseUint(s, 0, 32)
        fmt.Printf("%s %d.\n", s, ui)
    }
}
