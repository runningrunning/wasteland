package lissajous

import (
	"fmt"
	"image"
	"image/color"
	"image/gif"
	"io"
	"math"
	"math/rand"
	"tgpl/utils"
)

var palette_simple = []color.Color{color.Black, color.RGBA{0x0, 0xFF, 0x0, 0xFF}}

var palette_colorful = []color.Color{
	color.Black,
	color.RGBA{0x0, 0xFF, 0x0, 0xFF},
	color.RGBA{0xFF, 0x0, 0x0, 0xFF},
	color.RGBA{0x0, 0x0, 0xFF, 0xFF},
}

const (
	blackIndex        = 0
	GreenIndex        = 1
	RedIndex          = 2
	BlueIndex         = 3
	ColorNumber       = 4
	SimpleColorNumber = 2
)

func Lissajous(out io.Writer) {
	const (
		cycles  = 2
		res     = 0.001
		size    = 100
		nframes = 64
		delay   = 80
	)

	freq := rand.Float64() * 3.0
	anim := gif.GIF{LoopCount: nframes}
	phase := 0.0

	for i := 0; i < nframes; i++ {
		rect := image.Rect(0, 0, 2*size+1, 2*size+1)
		img := image.NewPaletted(rect, palette_simple)
		for t := 0.0; t < cycles*2*math.Pi; t += res {
			x := math.Sin(t)
			y := math.Sin(t*freq + phase)
			img.SetColorIndex(size+int(x*size+0.5), size+int(y*size+0.5), GreenIndex)
		}
		phase += 0.1
		anim.Delay = append(anim.Delay, delay)
		anim.Image = append(anim.Image, img)
	}
	gif.EncodeAll(out, &anim)
}

func LissajousColorful(out io.Writer) {
	const (
		cycles  = 2
		res     = 0.001
		size    = 100
		nframes = 64
		delay   = 8
	)

	freq := rand.Float64() * 3.0
	anim := gif.GIF{LoopCount: nframes}
	phase := 0.0

	for i := 0; i < nframes; i++ {
		rect := image.Rect(0, 0, 2*size+1, 2*size+1)
		img := image.NewPaletted(rect, palette_colorful)
		for t := 0.0; t < cycles*2*math.Pi; t += res {
			x := math.Sin(t)
			y := math.Sin(t*freq + phase)
			img.SetColorIndex(size+int(x*size+0.5), size+int(y*size+0.5), uint8(int(t*1000)%4))
		}
		phase += 0.1
		anim.Delay = append(anim.Delay, delay)
		anim.Image = append(anim.Image, img)
	}
	gif.EncodeAll(out, &anim)
}

type LissajousSet struct {
	Cycles, Size, Nframes, Delay int
	Res, Step                    float64
	Colorful                     bool
}

var set *LissajousSet

func CurrentSet() *LissajousSet {
	if set == nil {
		set = new(LissajousSet)
		set.Cycles = 2
		set.Size = 100
		set.Nframes = 64
		set.Delay = 8
		set.Res = 0.001
		set.Step = 0.1
		set.Colorful = false
	}
	return set
}

func (s *LissajousSet) SetComplete() {
	fmt.Printf("LissajousSet is DONE. Current is %v.\n", utils.DumpStruct(s))
}

func LissajousCustomized(out io.Writer) {
	freq := rand.Float64() * 3.0
	anim := gif.GIF{LoopCount: set.Nframes}
	phase := 0.0

	for i := 0; i < set.Nframes; i++ {
		rect := image.Rect(0, 0, 2*set.Size+1, 2*set.Size+1)
		img := image.NewPaletted(rect, palette_colorful)
		color := uint8(rand.Int() % ColorNumber)

		if !set.Colorful {
			color = GreenIndex
		}

		for t := 0.0; t < float64(set.Cycles)*2*math.Pi; t += set.Res {
			x := math.Sin(t)
			y := math.Sin(t*freq + phase)
			img.SetColorIndex(set.Size+int(x*float64(set.Size)+0.5),
				set.Size+int(y*float64(set.Size)+0.5), color)
		}

		phase += set.Step
		anim.Delay = append(anim.Delay, set.Delay)
		anim.Image = append(anim.Image, img)
	}
	gif.EncodeAll(out, &anim)
}
