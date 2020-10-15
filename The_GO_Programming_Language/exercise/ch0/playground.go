package main

import (
	"fmt"
	"math"
	"reflect"
	"strconv"
	"strings"
	"tgpl/utils"
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

type TestPtrOtherInterface interface {
	TestPtrInterface
	TestPtrOther() string
}

func (t *test) TestPtrOther() string {
	return "testPtrOther"
}

func tryRune() {
	newline := '\n'
	unicode := '国'
	fmt.Printf("%d %[1]q %[1]c\n", newline)
	fmt.Printf("%d %[1]q %[1]c\n", unicode)
}

func tryNumber() {
	var z float64
	fmt.Println(z, -z, 1/z, -1/z, z/z)

	nan := math.NaN()
	fmt.Println(nan == nan, nan < nan, nan > nan)
}

func tryReflect() {

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
}

func tryTypeAssertion() {
	s := test{Sv: "test"}

	// Interface Type Assertions
	var ptr TestPtrInterface
	ptr = &s
	ptro := ptr.(TestPtrOtherInterface)
	pt := ptr.(TestInterface)
	fmt.Printf("&s is %v %v %v %v %v\n", &s, s, ptr, ptro, pt)

	// Concert Type Assertions
	var x interface{}
	x = s
	it := x.(test)
	ipt := ptr.(*test)
	fmt.Printf("&s is %v it %v ipt %v\n", &s, it, ipt)

}

func tryStrconv() {
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

func tryUtils() {
	fmt.Printf("%v\n", utils.OutboundIP())
}

func tryArray() {
	a := [...]int{1, 2, 3} // array
	b := [...]int{3, 4, 5} // array
	c := []int{4, 5, 6}    // slice
	// fmt.Printf("%v %v %v.\n", a, b, a + b)
	fmt.Printf("%T %[1]v %T %[2]v %T %[3]v.\n", a, b, c)
}

func tryFuncReturn() {
	x, y := func() (int, int) {
		return 1, 2
	}()
	fmt.Printf("%v %v.\n", x, y)

	x_, y_ := func() (int, int) {
		return 3, 4
	}()

	fmt.Printf("%v %v.\n", x, y)
}

func main() {
	tryRune()
	tryNumber()
	tryReflect()
	tryTypeAssertion()
	tryStrconv()
	tryUtils()
	tryArray()
	tryFuncReturn()
}
