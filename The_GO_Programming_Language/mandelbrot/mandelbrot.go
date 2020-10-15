package mandelbrot

import (
	"fmt"
	"image"
	"image/color"
	"image/png"
	"io"
	"math/cmplx"
	"tgpl/utils"
)

// Try Meta Programming
type ValueType interface {}

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
	xyrange       float64
	width, height int
}

var set *MandelbrotSet

func CurrentSet() *MandelbrotSet {
	if set == nil {
		set = new(MandelbrotSet)
		set.Style = "default"
		set.Method = "newton"
		set.Supersampling = false
		set.X = -2.0
		set.Y = -2.0
		set.Zoom = 1
		set.xyrange = 4.0
		set.width = 2048
		set.height = 2048
	}
	return set
}

func (s *MandelbrotSet) SetComplete() {
	fmt.Printf("MandelbrotSet is DONE. Current is %v.\n", utils.DumpStruct(s))
}

func FractalMethod(z complex128) color.Color {
	switch set.Method {
	case "mandelbrot":
		return mandelbrot(z)
	case "newton":
		return newton(1, z)
	}
	return mandelbrot(z)
}

func Mandelbrot(o io.Writer) {
	var xmin, ymin, xmax, ymax float64

	xmin = set.X
	ymin = set.Y

	xmax = xmin + set.xyrange/set.Zoom
	ymax = ymin + set.xyrange/set.Zoom

	w, h := set.width, set.height
	if set.Supersampling {
		w *= 2
		h *= 2
	}

	img := image.NewRGBA(image.Rect(0, 0, w, h))
	for py := 0; py < h; py++ {
		y := float64(py)/float64(h)*(ymax-ymin) + ymin
		for px := 0; px < w; px++ {
			x := float64(px)/float64(w)*(xmax-xmin) + xmin
			z := complex(x, y)
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

func mandelbrot(z complex128) color.Color {
	const iterations = 255
	var v complex128
	for n := uint8(0); n < iterations; n++ {
		v = v*v + z
		if cmplx.Abs(v) > 2 {
			return colorStyle(n)
		}
	}
	return color.Black
}

func NewtonFunction(z complex128) complex128 {
	return z*z*z*z - 1
}

func NewtonDerivative(z complex128) complex128 {
	return 4 * z * z * z
}

var newtonRoots []complex128

func init() {
	// Roots for z * z * z * z - 1
	newtonRoots = []complex128{1, -1, 1i, -1i}
}

func newton(a, z complex128) color.Color {
	const iterations = 255
	const contrast = 15
	var v = z
	for n := uint8(0); n < iterations; n++ {
		v -= a * NewtonFunction(v) / NewtonDerivative(v)
		for _, r := range newtonRoots {
			// tolerance 0.00001
			if cmplx.Abs(v-r) < 0.001 {
				return colorStyle(n)
			}
		}
	}
	return color.Black
}
