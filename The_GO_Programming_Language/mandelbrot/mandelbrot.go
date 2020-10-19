package mandelbrot

import (
	"fmt"
	"image"
	"image/color"
	"image/png"
	"io"
	"log"
	"math"
	"math/big"
	"math/cmplx"
	"tgpl/utils"
)

// TODO how to recover from the panic
// TODO Add more newton methods!

// So what's the difference ?

// float32 == float64 > big.Float > big.Rat
// big.Float is slower
// big.Rat will keep everything in a /b form, so it's the slowest version.
// iteration > 32 will run infinity

// Try Meta Programming
// The pointer to interface is not interface
// Methods are defined on the concrete types implementing an interface.
// Can not use interface Type as receiver !
type ValueType interface{}

// https://golang.org/doc/faq#overloading
// Go doesn't support overloading of methods and operators

type Float32Complex struct {
	c complex64
}

type Float64Complex struct {
	c complex128
}

type BigFloatComplex struct {
	r, i *big.Float
}

type BigRatComplex struct {
	r, i *big.Rat
}

func IsInvalid(a ValueType) bool {
	switch a.(type) {
	case *Float32Complex:
		ca := a.(*Float32Complex)
		return cmplx.IsInf(complex128(ca.c))
	case *Float64Complex:
		ca := a.(*Float64Complex)
		return cmplx.IsInf(ca.c)
	case *BigFloatComplex:
		ca := a.(*BigFloatComplex)
		return ca.r.IsInf() || ca.i.IsInf()
	case *BigRatComplex:
		// big rat can not be inf ?
		return false
	}
	return true
}

func IsZero(a ValueType) bool {
	switch a.(type) {
	case *Float32Complex:
		ca := a.(*Float32Complex)
		return ca.c == 0
	case *Float64Complex:
		ca := a.(*Float64Complex)
		return ca.c == 0
	case *BigFloatComplex:
		ca := a.(*BigFloatComplex)
		return ca.r.Cmp(new(big.Float).SetFloat64(float64(0))) == 0 &&
			ca.i.Cmp(new(big.Float).SetFloat64(float64(0))) == 0
	case *BigRatComplex:
		ca := a.(*BigRatComplex)
		return ca.r.Cmp(new(big.Rat).SetFloat64(float64(0))) == 0 &&
			ca.i.Cmp(new(big.Rat).SetFloat64(float64(0))) == 0
	}
	return true
}

func Add(a, b ValueType) ValueType {
	switch a.(type) {
	case *Float32Complex:
		ca := a.(*Float32Complex)
		cb := b.(*Float32Complex)
		ca.c += cb.c
	case *Float64Complex:
		ca := a.(*Float64Complex)
		cb := b.(*Float64Complex)
		ca.c += cb.c
	case *BigFloatComplex:
		ca := a.(*BigFloatComplex)
		cb := b.(*BigFloatComplex)
		ca.r.Add(ca.r, cb.r)
		ca.i.Add(ca.i, cb.i)
	case *BigRatComplex:
		ca := a.(*BigRatComplex)
		cb := b.(*BigRatComplex)
		ca.r.Add(ca.r, cb.r)
		ca.i.Add(ca.i, cb.i)
	default:
		log.Fatal("Should not be here as r %v i %v.\n", a, b)
	}
	return a
}

func Sub(a, b ValueType) ValueType {
	switch a.(type) {
	case *Float32Complex:
		ca := a.(*Float32Complex)
		cb := b.(*Float32Complex)
		ca.c -= cb.c
	case *Float64Complex:
		ca := a.(*Float64Complex)
		cb := b.(*Float64Complex)
		ca.c -= cb.c
	case *BigFloatComplex:
		ca := a.(*BigFloatComplex)
		cb := b.(*BigFloatComplex)
		ca.r.Sub(ca.r, cb.r)
		ca.i.Sub(ca.i, cb.i)
	case *BigRatComplex:
		ca := a.(*BigRatComplex)
		cb := b.(*BigRatComplex)
		ca.r.Sub(ca.r, cb.r)
		ca.i.Sub(ca.i, cb.i)
	default:
		log.Fatal("Should not be here as r %v i %v.\n", a, b)
	}
	return a
}

//                       t1      t2       t3      t4
// (a + bi) * (c + di) = a * c - b * d + (a * d + b * c)i
func (a *BigFloatComplex) Mul(b *BigFloatComplex) *BigFloatComplex {
	t1 := new(big.Float).Set(a.r)
	t1.Mul(t1, b.r)

	t2 := new(big.Float).Set(a.i)
	t2.Mul(t2, b.i)

	t1.Sub(t1, t2)

	t3 := new(big.Float).Set(a.r)
	t3.Mul(t3, b.i)

	t4 := new(big.Float).Set(a.i)
	t4.Mul(t4, b.r)

	t3.Add(t3, t4)

	a.r.Set(t1)
	a.i.Set(t3)
	return a
}

//                       t1      t2       t3      t4
// (a + bi) * (c + di) = a * c - b * d + (a * d + b * c)i
func (a *BigRatComplex) Mul(b *BigRatComplex) *BigRatComplex {
	t1 := new(big.Rat).Set(a.r)
	t1.Mul(t1, b.r)

	t2 := new(big.Rat).Set(a.i)
	t2.Mul(t2, b.i)

	t1.Sub(t1, t2)

	t3 := new(big.Rat).Set(a.r)
	t3.Mul(t3, b.i)

	t4 := new(big.Rat).Set(a.i)
	t4.Mul(t4, b.r)

	t3.Add(t3, t4)

	a.r.Set(t1)
	a.i.Set(t3)
	return a
}

// https://mathworld.wolfram.com/ComplexDivision.html
//                         t1   t2   t3   t4     t5   t6   t3   t4
// (a + bi) / (c + di) => (ac + bd)/(cc + dd) + (bc - ad)/(cc + dd) i
func (a *BigFloatComplex) Quo(b *BigFloatComplex) *BigFloatComplex {
	t1 := new(big.Float).Set(a.r)
	t1.Mul(t1, b.r)

	t2 := new(big.Float).Set(a.i)
	t2.Mul(t2, b.i)

	t1.Add(t1, t2)

	t3 := new(big.Float).Set(b.r)
	t3.Mul(t3, b.r)

	t4 := new(big.Float).Set(b.i)
	t4.Mul(t4, b.i)

	t3.Add(t3, t4)

	t1.Quo(t1, t3)

	t5 := new(big.Float).Set(a.i)
	t5.Mul(t5, b.r)

	t6 := new(big.Float).Set(a.r)
	t6.Mul(t6, b.i)

	t5.Sub(t5, t6)

	t5.Quo(t5, t3)

	a.r.Set(t1)
	a.i.Set(t5)
	return a
}

// https://mathworld.wolfram.com/ComplexDivision.html
//                         t1   t2   t3   t4     t5   t6   t3   t4
// (a + bi) / (c + di) => (ac + bd)/(cc + dd) + (bc - ad)/(cc + dd) i
func (a *BigRatComplex) Quo(b *BigRatComplex) *BigRatComplex {
	t1 := new(big.Rat).Set(a.r)
	t1.Mul(t1, b.r)

	t2 := new(big.Rat).Set(a.i)
	t2.Mul(t2, b.i)

	t1.Add(t1, t2)

	t3 := new(big.Rat).Set(b.r)
	t3.Mul(t3, b.r)

	t4 := new(big.Rat).Set(b.i)
	t4.Mul(t4, b.i)

	t3.Add(t3, t4)

	t1.Quo(t1, t3)

	t5 := new(big.Rat).Set(a.i)
	t5.Mul(t5, b.r)

	t6 := new(big.Rat).Set(a.r)
	t6.Mul(t6, b.i)

	t5.Sub(t5, t6)

	t5.Quo(t5, t3)

	a.r.Set(t1)
	a.i.Set(t5)
	return a
}

func (a *BigFloatComplex) Abs() float64 {
	t1 := new(big.Float).Set(a.r)
	t1.Mul(t1, a.r)

	t2 := new(big.Float).Set(a.i)
	t2.Mul(t2, a.i)

	t1.Add(t1, t2)
	t1.Sqrt(t1)

	f, _ := t1.Float64()
	return f
}

func (a *BigRatComplex) Abs() float64 {
	t1 := new(big.Rat).Set(a.r)
	t1.Mul(t1, a.r)

	t2 := new(big.Rat).Set(a.i)
	t2.Mul(t2, a.i)

	t1.Add(t1, t2)

	// Rat doesn't have sqrt
	f, _ := t1.Float64()
	return math.Sqrt(f)
}

func Mul(a, b ValueType) ValueType {
	switch a.(type) {
	case *Float32Complex:
		ca := a.(*Float32Complex)
		cb := b.(*Float32Complex)
		ca.c *= cb.c
	case *Float64Complex:
		ca := a.(*Float64Complex)
		cb := b.(*Float64Complex)
		ca.c *= cb.c
	case *BigFloatComplex:
		ca := a.(*BigFloatComplex)
		cb := b.(*BigFloatComplex)
		ca.Mul(cb)
	case *BigRatComplex:
		ca := a.(*BigRatComplex)
		cb := b.(*BigRatComplex)
		ca.Mul(cb)
	default:
		log.Fatal("Should not be here as r %v i %v.\n", a, b)
	}
	return a
}

func Quo(a, b ValueType) ValueType {
	switch a.(type) {
	case *Float32Complex:
		ca := a.(*Float32Complex)
		cb := b.(*Float32Complex)
		ca.c /= cb.c
	case *Float64Complex:
		ca := a.(*Float64Complex)
		cb := b.(*Float64Complex)
		ca.c /= cb.c
	case *BigFloatComplex:
		ca := a.(*BigFloatComplex)
		cb := b.(*BigFloatComplex)
		ca.Quo(cb)
	case *BigRatComplex:
		ca := a.(*BigRatComplex)
		cb := b.(*BigRatComplex)
		ca.Quo(cb)
	default:
		log.Fatal("Should not be here as r %v i %v.\n", a, b)
	}
	return a
}

func Abs(a ValueType) float64 {
	switch a.(type) {
	case *Float32Complex:
		ca := a.(*Float32Complex)
		return cmplx.Abs(complex128(ca.c))
	case *Float64Complex:
		ca := a.(*Float64Complex)
		return cmplx.Abs(ca.c)
	case *BigFloatComplex:
		ca := a.(*BigFloatComplex)
		return ca.Abs()
	case *BigRatComplex:
		ca := a.(*BigRatComplex)
		return ca.Abs()
	default:
		log.Fatal("Should not be here as a %v.\n", a)
	}
	return 0
}

func Clone(a ValueType) ValueType {
	switch a.(type) {
	case *Float32Complex:
		ca := a.(*Float32Complex)
		return &Float32Complex{ca.c}
	case *Float64Complex:
		ca := a.(*Float64Complex)
		return &Float64Complex{ca.c}
	case *BigFloatComplex:
		ca := a.(*BigFloatComplex)
		return &BigFloatComplex{new(big.Float).Set(ca.r), new(big.Float).Set(ca.i)}
	case *BigRatComplex:
		ca := a.(*BigRatComplex)
		return &BigRatComplex{new(big.Rat).Set(ca.r), new(big.Rat).Set(ca.i)}
	}
	log.Fatal("Should not be here as a %v.\n", a)
	return a
}

func dump(a ValueType) string {
	switch a.(type) {
	case *Float32Complex:
		return fmt.Sprintf("%v", a.(*Float32Complex).c)
	case *Float64Complex:
		return fmt.Sprintf("%v", a.(*Float64Complex).c)
	case *BigFloatComplex:
		ca := a.(*BigFloatComplex)
		return fmt.Sprintf("%v:%v", ca.r, ca.i)
	case *BigRatComplex:
		ca := a.(*BigRatComplex)
		return fmt.Sprintf("%v:%v", ca.r, ca.i)
	}
	return ""
}

func (c *Float32Complex) Real() float32 {
	return real(c.c)
}

func (c *Float64Complex) Real() float64 {
	return real(c.c)
}

func (c *BigFloatComplex) Real() *big.Float {
	return new(big.Float).Set(c.r)
}

func (c *BigRatComplex) Real() *big.Rat {
	return new(big.Rat).Set(c.r)
}

func NewValueType(r, i float64) ValueType {
	switch set.Typestring {
	case "complex64":
		return &Float32Complex{complex(float32(r), float32(i))}
	case "complex128":
		return &Float64Complex{complex(r, i)}
	case "bigfloat":
		return &BigFloatComplex{big.NewFloat(r), big.NewFloat(i)}
	case "bigrat":
		return &BigRatComplex{new(big.Rat).SetFloat64(r), new(big.Rat).SetFloat64(i)}
	default:
		return &Float64Complex{complex(r, i)}
	}
}

func NewComplexType(r, i ValueType) ValueType {
	switch r.(type) {
	case *Float32Complex:
		cr := r.(*Float32Complex)
		ci := i.(*Float32Complex)
		return &Float32Complex{complex(cr.Real(), ci.Real())}
	case *Float64Complex:
		cr := r.(*Float64Complex)
		ci := i.(*Float64Complex)
		return &Float64Complex{complex(cr.Real(), ci.Real())}
	case *BigFloatComplex:
		cr := r.(*BigFloatComplex)
		ci := i.(*BigFloatComplex)
		return &BigFloatComplex{cr.Real(), ci.Real()}
	case *BigRatComplex:
		cr := r.(*BigRatComplex)
		ci := i.(*BigRatComplex)
		return &BigRatComplex{cr.Real(), ci.Real()}
	}
	log.Fatal("Should not be here as r %v i %v.\n", r, i)
	return nil
}

func DefaultValueType() ValueType {
	return NewValueType(0, 0)
}

func colorStyle(n uint8) color.Color {
	const contrast = 15
	switch set.Style {
	case "colorful":
		switch n % 3 {
		case 0:
			return color.RGBA{255 - contrast*n, n, n, 255 - contrast*n}
		case 1:
			return color.RGBA{n, 255 - contrast*n, n, 255 - contrast*n}
		case 2:
			return color.RGBA{n, n, 255 - contrast*n, 255 - contrast*n}
		}
	case "black":
		return color.RGBA{n, n, n, 255 - contrast*n}
	case "red":
		return color.RGBA{255 - contrast*n, n, n, 255}
	case "green":
		return color.RGBA{n, 255 - contrast*n, n, 255}
	case "blue":
		return color.RGBA{n, n, 255 - contrast*n, 255}
	case "default":
		return color.Gray{255 - contrast*n}
	}
	return color.Gray{255 - contrast*n}
}

type MandelbrotSet struct {
	Method, Style string
	Supersampling bool
	X, Y          float64
	Zoom          float64
	Newtona       float64 // Only used in Newton https://en.wikipedia.org/wiki/Newton_fractal
	Newtonc       float64 // Only used in Newton https://en.wikipedia.org/wiki/Newton_fractal
	Typestring    string  // ValueType string
	xyrange       float64
	width, height int
	valueX        ValueType
	valueY        ValueType
	valueZoom     ValueType
	valueXYRange  ValueType
	valueNewtonA  ValueType
	valueNewtonC  ValueType
}

var set *MandelbrotSet

const (
	StartX      float64 = -2.0
	StartY      float64 = -2.0
	DefaultZoom float64 = 1.0
	XYRange     float64 = 4.0
	Width       int     = 512
	Height      int     = 512
	NewtonA     float64 = 1.0
	NewtonC     float64 = 0
)

func CurrentSet() *MandelbrotSet {
	if set == nil {
		set = new(MandelbrotSet)
		set.Method = "mandelbrot"
		set.Style = "default"
		set.Supersampling = false
		set.X = StartX
		set.Y = StartY
		set.Zoom = DefaultZoom
		set.Newtona = NewtonA
		set.Newtonc = NewtonC
		set.Typestring = "default"
		set.xyrange = XYRange
		set.width = Width
		set.height = Height
	}
	set.SetComplete()
	return set
}

func (s *MandelbrotSet) SetComplete() {
	set.valueX = NewValueType(set.X, 0)
	set.valueY = NewValueType(set.Y, 0)
	set.valueNewtonA = NewValueType(set.Newtona, 0)
	set.valueNewtonC = NewValueType(set.Newtonc, 0)

	// Calculate the real range through zoom level
	set.valueZoom = NewValueType(set.Zoom, 0)
	set.valueXYRange = NewValueType(set.xyrange, 0)
	Quo(set.valueXYRange, set.valueZoom)

	// Regenerate the root as it the value type depends on the input
	newtonRoots = NewtonRoots()

	fmt.Printf("MandelbrotSet is DONE. Current is %v.\n", utils.DumpStruct(s))
}

func FractalMethod(z ValueType) color.Color {
	switch set.Method {
	case "mandelbrot":
		return mandelbrot(z)
	case "newton":
		return newton(z)
	}
	return mandelbrot(z)
}

func Mandelbrot(o io.Writer) {
	xmin := set.valueX
	ymin := set.valueY

	w, h := set.width, set.height

	if set.Supersampling {
		w *= 2
		h *= 2
	}

	img := image.NewRGBA(image.Rect(0, 0, w, h))
	for py := 0; py < h; py++ {
		y := NewValueType(float64(py), 0)
		Quo(y, NewValueType(float64(h), 0))
		Mul(y, set.valueXYRange)
		Add(y, ymin)
		// y := float64(py)/float64(h)*(ymax-ymin) + ymin
		for px := 0; px < w; px++ {
			x := NewValueType(float64(px), 0)
			Quo(x, NewValueType(float64(w), 0))
			Mul(x, set.valueXYRange)
			Add(x, xmin)
			// x := float64(px)/float64(w)*(xmax-xmin) + xmin
			z := NewComplexType(x, y)
			img.Set(px, py, FractalMethod(z))
		}
	}

	if !set.Supersampling {
		png.Encode(o, img)
		return
	}

	sampled := image.NewRGBA(image.Rect(0, 0, set.width, set.height))

	for py := 0; py < h; py++ {
		for px := 0; px < w; px++ {
			var r, g, b, a uint32
			cx := px * 2
			cy := py * 2
			_r, _g, _b, _a := img.At(cx, cy).RGBA()
			r += _r
			g += _g
			b += _b
			a += _a
			_r, _g, _b, _a = img.At(cx, cy+1).RGBA()
			r += _r
			g += _g
			b += _b
			a += _a
			_r, _g, _b, _a = img.At(cx+1, cy).RGBA()
			r += _r
			g += _g
			b += _b
			a += _a
			_r, _g, _b, _a = img.At(cx+1, cy+1).RGBA()
			r += _r
			g += _g
			b += _b
			a += _a
			sampled.Set(px, py, color.RGBA{uint8(r / 4),
				uint8(g / 4), uint8(b / 4), uint8(a / 4)})
		}
	}

	png.Encode(o, sampled)
}

func mandelbrot(z ValueType) color.Color {
	const iterations = 255
	v := DefaultValueType()
	for n := uint8(0); n < iterations; n++ {
		Mul(v, v)
		Add(v, z)
		// v = v*v + z
		if Abs(v) > 2 {
			// if cmplx.Abs(v) > 2 {
			return colorStyle(n)
		}
	}
	return color.Black
}

func NewtonRoots() []ValueType {
	// Roots for z * z * z * z - 1
	return []ValueType{
		NewValueType(1, 0),
		NewValueType(-1, 0),
		NewValueType(0, 1),
		NewValueType(0, -1),
	}
}

// z * z * z * z - 1 =0
func NewtonFunction(z ValueType) ValueType {
	x := Clone(z)
	Mul(x, z)
	Mul(x, z)
	Mul(x, z)
	Sub(x, NewValueType(float64(1), 0))
	return x
	// return z*z*z*z - 1
}

func NewtonDerivative(z ValueType) ValueType {
	x := Clone(z)
	Mul(x, z)
	Mul(x, z)
	Mul(x, NewValueType(float64(4), 0))
	return x
	// return 4 * z * z * z
}

var newtonRoots []ValueType

func init() {
	CurrentSet()
}

func newton(z ValueType) color.Color {
	a := set.valueNewtonA
	c := set.valueNewtonC

	const iterations = 255
	const contrast = 15

	v := Clone(z)
	for n := uint8(0); n < iterations; n++ {
		d := NewtonFunction(v)
		dr := NewtonDerivative(v)

		if IsInvalid(d) || IsInvalid(dr) {
			fmt.Printf("%s or %s is Invalid.\n", dump(d), dump(dr))
			break
		}

		if IsZero(dr) {
			fmt.Printf("%s is Zero.\n", dump(dr))
			break
		}

		Quo(d, dr)
		Mul(d, a)
		Sub(v, d)
		Add(v, c)
		// v -= a * NewtonFunction(v) / NewtonDerivative(v)
		for _, r := range newtonRoots {
			// tolerance 0.00001
			dv := Clone(v)
			Sub(dv, r)
			if Abs(dv) < 0.00001 {
				return colorStyle(n)
			}
		}
	}
	return color.Black

}
