package main

import (
	"fmt"
	"math"
	"math/big"
	"math/cmplx"
	"reflect"
	"strconv"
	"strings"
	"tgpl/utils"
	"unicode/utf8"
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
	fmt.Printf("%v %v.\n", x_, y_)
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

type TestType struct {
	x, y int
}

func tryTypeSwitch() {
	checkType := func(x interface{}) {
		switch x := x.(type) {
		case string:
			fmt.Printf("it's string %v.\n", x)
		case int:
			fmt.Printf("it's int %v.\n", x)
		case int64:
			fmt.Printf("it's int6 %v.\n", x)
		case complex128:
			fmt.Printf("it's complex128 %v.\n", x)
		case float64:
			fmt.Printf("it's float64 %v.\n", x)
		case TestType:
			fmt.Printf("it's TestType %v.\n", x)
		case *TestType:
			fmt.Printf("it's TestType %v.\n", x)
		}
	}

	checkType("abc")
	checkType(1)
	checkType(int64(1))
	checkType(complex128(1 + 10i))
	checkType(complex128(1+10i) / complex128(2i))
	checkType(complex128(1+10i) / complex128(1+2i))
	checkType(3.1415926)
	checkType(TestType{1, 2})
	checkType(&TestType{1, 2})
	checkType(cmplx.Abs(1 + 2i))
}

// Can not defined new methods on non-local type complex128
// func (c complex128) Real() float64 {
// 	return real(c)
// }

// func tryTypeFunction() {
// 	a := 1 + 5i
// 	fmt.Printf("a is %v real is %v.\n", a, a.Real())
// }

func tryBigRat() {
	fmt.Printf("%v, %v.\n", new(big.Rat).SetFloat64(3))
}

func tryUint8() {
	var test uint8 = 10
	fmt.Printf("%v %v.\n", test, test-255)
}

func tryPointer() {
	// cannont take the address of "abc"
	// s := &"abc"
	s := "abc"
	t := &s
	*t = "bcd"

	fmt.Printf("%v %v %v.\n", s, t, *t)
}

func tryString() {
	s := `abc
xyz`
	n := "abc\nxyz"
	fmt.Printf("%v %d %v %d %v.\n", s, len(s), n, len(n), s == n)

	for i := 0; i < len(s); i++ {
		if s[i] != n[i] {
			fmt.Printf("it's %d and %v %v.\n", i, s[i], n[i])
		}
	}

	s1 := "世界"
	s2 := "\xe4\xb8\x96\xe7\x95\x8c"
	s3 := "\u4e16\u754c"
	s4 := "\U00004e16\U0000754c"

	fmt.Printf("len %d %d %d %d.\n", len(s1), len(s2), len(s3), len(s4))
	fmt.Printf("runelen %d %d %d %d.\n", utf8.RuneCountInString(s1), utf8.RuneCountInString(s2), utf8.RuneCountInString(s3), utf8.RuneCountInString(s4))
	fmt.Printf("value %v %v %v %v.\n", (s1), (s2), (s3), (s4))

	for i := 0; i < len(s1); i++ {
		fmt.Printf("%v %[1]X %[1]b\n", s1[i])
	}

	for _, c := range s1 {
		fmt.Printf("%v %[1]c %[1]q \n", c)
	}

	fmt.Printf("%c %[1]q\n", '\uFFFD')

	fmt.Printf("%x \n", []rune(s1))
	fmt.Printf("%d \n", []rune(s4))
	fmt.Printf("%x \n", []byte(s4))
	fmt.Printf("%d \n", []byte(s4))
	fmt.Printf("%x \n", s1)
	fmt.Printf("%d \n", s4)
}

func tryIota() {
	type Weekday int
	const (
		Sunday Weekday = iota
		Monday
	)

	const (
		_ = 1 << (10 * iota)
		KiB
		MiB
		GiB
		TiB
		PiB
		EiB
		ZiB
		YiB
	)

	// fmt.Printf("%v %v\n", KiB, YiB) // constant 1208925819614629174706176 overflows int
	fmt.Println(YiB / ZiB)
	fmt.Printf("%d %d\n", Monday, Sunday)

	var x float32 = math.Pi
	var y float64 = math.Pi

	fmt.Printf("%g %g\n", x, y)
}

func _tryPassArray(input [3]int) {
	input[0] = 2000
}
func _tryPassArrayPointer(input *[3]int) {
	(*input)[0] = 1000
}

func _tryPassSlice(input []int) {
	if len(input) > 0 {
		input[0] = 10000
	}
}

func _tryPassSlicePointer(input *[]int) {
	if len(*input) > 0 {
		(*input)[0] = 20000
	}
}

func tryPassArray() {
	input := [...]int{1, 2, 3} // type is [3]int
	_tryPassArray(input)
	fmt.Printf("%T %[1]v.\n", input) // failed
	_tryPassArrayPointer(&input)
	fmt.Printf("%T %[1]v.\n", &input) // successful

	inputSlice := []int{3, 2, 1} // type is []int, a slice
	_tryPassSlice(inputSlice)
	fmt.Printf("%T %[1]v.\n", inputSlice) // successful
	_tryPassSlicePointer(&inputSlice)
	fmt.Printf("%T %[1]v.\n", &inputSlice) // succesful

	// Can modify the array through slice
	inputSlice = input[0:]                // Create a slice base on input
	fmt.Printf("%T %[1]v.\n", inputSlice) // successful
	_tryPassSlice(inputSlice)
	fmt.Printf("%T %[1]v.\n", inputSlice) // successful
	fmt.Printf("%T %[1]v.\n", input)      // successful

	// Why string => []byte array is OK, but not [3]int => [] int
	b := []byte("x")
	fmt.Printf("\"x\" is %T %[1]v, %T %[2]v.\n", "x", b)
	// inputSlice = []int(input) // Can not convert input (type [3]int) to type []int

	// [3]byte => []byte is not OK
	c := [...]byte{1, 3, 4}
	// b = []byte(c)
	b = c[0:]
	fmt.Printf("c is %T %[1]v, %T %[2]v.\n", c, b)
}

type Employee struct {
	ID     int
	Salary int
	team   int
}

var dilbert Employee

func EmployeeByID(id int) *Employee {
	return &dilbert
}

// func EmployeeByID(id int) Employee {
// 	return dilbert
// }

func tryReturnType() {
	EmployeeByID(0).Salary = 0
}

func NewEmployee(team int) Employee {
	e := Employee{}
	e.ID = 0
	e.Salary = 500
	e.team = team
	return e
}

func tryStructCompare() {
	a := NewEmployee(0)
	b := NewEmployee(1)
	fmt.Printf("a %v b %v == %v.\n", a, b, a == b)
}

func tryAnonymousFields() {
	type Point struct {
		X, Y int
	}

	type Circle struct {
		Point
		Radius int
	}

	type Wheel struct {
		Circle
		Spokes int
	}

	type Wrong struct {
		Circle
		*Point
		Wheel
		error int
		X int
	}

	p := Point{X:1, Y: 2}

	// cannot use promoted field Point.X in struct literal of type Circle
	// cannot use promoted field Circle.Radius in struct literal of type Wheel
	// cannot use promoted field Circle.Point.X in struct literal of type Wheel
	// c := Circle{X:1, Radius: 10}
	// w := Wheel{Radius: 20, X:10}
	c := Circle{Radius: 100}
	w := Wheel{Spokes: 20}

	c.X = 100
	w.Radius = 1000

	fmt.Println(p, c, w)

	fmt.Println(p)
	r := Wrong{error:404}
	// r.Point = &Point{1, 1}
	r.Point = &p
	r.X = 1000
	r.Radius = 101
	r.Y = 303
	r.Circle.X = 50
	fmt.Println(r.Point)
	fmt.Println(r)

	q := Wrong{Circle{Point{8, 8}, 10},
		&Point{10, 10}, Wheel{Spokes:5,Circle:Circle{Point{4, 4}, 7},},
		8, 100}
	fmt.Println(q, q.X, q.Y)
	fmt.Printf("%#v\n%#v\n", r, q)
}

func main() {
	tryRune()
	tryNumber()
	tryReflect()
	tryStrconv()
	tryUtils()
	tryArray()
	tryFuncReturn()
	tryTypeAssertion()
	tryTypeSwitch()
	tryBigRat()
	tryUint8()
	tryPointer()
	tryString()
	tryIota()
	tryPassArray()
	tryReturnType()
	tryStructCompare()
	tryAnonymousFields()
}
