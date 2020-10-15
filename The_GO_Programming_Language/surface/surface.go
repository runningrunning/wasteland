/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package surface

import (
	"fmt"
	"io"
	"math"
    "tgpl/utils"
)

type CalcZ func(float64, float64) float64

// const doesn't need type ?
const (
	width, height = 600, 320
	cells         = 100
	xyrange       = 30.0
	xyscale       = width / 2 / xyrange
	zscale        = height * 0.4
	angle         = math.Pi / 6
)

var sin30, cos30 = math.Sin(angle), math.Cos(angle)

type NaN struct{}
type Inf struct{}

func (nan NaN) Error() string {
	return "Is NaN"
}

func (inf Inf) Error() string {
	return "Is Inf"
}

func corner(c CalcZ, i, j int) (float64, float64, error) {
	// Find point (x,y) at corner of cell(i,j)
	x := xyrange * (float64(i)/cells - 0.5)
	y := xyrange * (float64(j)/cells - 0.5)

	// Compute surface height z
	z := c(x, y)

	if math.IsNaN(z) {
		return 0, 0, NaN{}
	}

	if math.IsInf(z, 0) {
		return 0, 0, Inf{}
	}

	// Project (x,y,z) isometrically onto 2-D SVG canvas (sx, sy)
	sx := width/2 + (x-y)*cos30*xyscale
	sy := height/2 + (x+y)*sin30*xyscale - z*zscale
	return sx, sy, nil
}

func Surface(c CalcZ) {
	fmt.Printf("<svg xmlns='http://www.w3.org/2000/svg' "+
		"style='stroke: grey; fill: white; stroke-width: 0.7' "+
		"width='%d' height='%d'>", width, height)

	for i := 0; i < cells; i++ {
		for j := 0; j < cells; j++ {
			var err error
			ax, ay, err := corner(c, i+1, j)
			if err != nil {
				continue
			}
			bx, by, err := corner(c, i, j)
			if err != nil {
				continue
			}
			cx, cy, err := corner(c, i, j+1)
			if err != nil {
				continue
			}
			dx, dy, err := corner(c, i+1, j+1)
			if err != nil {
				continue
			}
			fmt.Printf("<polygon points='%g,%g %g,%g %g,%g %g,%g'/>\n",
				ax, ay, bx, by, cx, cy, dx, dy)
		}
	}
	fmt.Println("</svg>")
}

func SurfaceIO(c CalcZ, out io.Writer) {
	fmt.Fprintf(out, "<svg xmlns='http://www.w3.org/2000/svg' "+
		"style='stroke: grey; fill: white; stroke-width: 0.7' "+
		"width='%d' height='%d'>", width, height)

	for i := 0; i < cells; i++ {
		for j := 0; j < cells; j++ {
			var err error
			var ax, ay, bx, by, cx, cy, dx, dy float64
			if ax, ay, err = corner(c, i+1, j); err != nil {
				continue
			}
			if bx, by, err = corner(c, i, j); err != nil {
				continue
			}
			if cx, cy, err = corner(c, i, j+1); err != nil {
				continue
			}
			if dx, dy, err = corner(c, i+1, j+1); err != nil {
				continue
			}

			fmt.Fprintf(out, "<polygon points='%g,%g %g,%g %g,%g %g,%g'/>\n",
				ax, ay, bx, by, cx, cy, dx, dy)
		}
	}

	fmt.Fprintf(out, "</svg>\n")
}

// -1 < z > 1, color from #ff0000 -> #0000ff
func colorfulZ(z float64) int32 {
	maxz := 1.0
	minz := -0.05
	if z <= 0 {
		z *= 256 / (0 - minz)
		if z < -255 {
			z = -255
		}
		return 0xff0000 + 255 + int32(z)
	} else {
		z *= 256 / maxz
		if z >= 255 {
			z = 255
		}
		return (255-int32(z))<<16 + 255
	}
}

func colorCorner(c CalcZ, i, j int) (float64, float64, int32, error) {
	// Find point (x,y) at corner of cell(i,j)
	x := xyrange * (float64(i)/cells - 0.5)
	y := xyrange * (float64(j)/cells - 0.5)

	// Compute surface height z
	z := c(x, y)
	cz := colorfulZ(z)

	if math.IsNaN(z) {
		return 0, 0, cz, NaN{}
	}

	if math.IsInf(z, 0) {
		return 0, 0, cz, Inf{}
	}

	// Project (x,y,z) isometrically onto 2-D SVG canvas (sx, sy)
	sx := width/2 + (x-y)*cos30*xyscale
	sy := height/2 + (x+y)*sin30*xyscale - z*zscale
	return sx, sy, cz, nil
}

func SurfaceIOColorful(c CalcZ, out io.Writer) {
	fmt.Fprintf(out, "<svg xmlns='http://www.w3.org/2000/svg' "+
		"style='stroke: grey; fill: white; stroke-width: 0.7' "+
		"width='%d' height='%d'>", width, height)

	for i := 0; i < cells; i++ {
		for j := 0; j < cells; j++ {
			var err error
			var ax, ay, bx, by, cx, cy, dx, dy float64
			var ac, bc, cc, dc int32
			if ax, ay, ac, err = colorCorner(c, i+1, j); err != nil {
				continue
			}
			if bx, by, bc, err = colorCorner(c, i, j); err != nil {
				continue
			}
			if cx, cy, cc, err = colorCorner(c, i, j+1); err != nil {
				continue
			}
			if dx, dy, dc, err = colorCorner(c, i+1, j+1); err != nil {
				continue
			}
			ac += bc + cc + dc
			fmt.Fprintf(out, "<polygon points='%g,%g %g,%g %g,%g %g,%g' "+
				"style='stroke: #%x; fill: white; stroke-width: 0.7' />\n",
				ax, ay, bx, by, cx, cy, dx, dy, ac/4)
		}
	}

	fmt.Fprintf(out, "</svg>\n")
}

type SurfaceSet struct {
	Color, Cells, Height, Width               int
	Xyrange, Xyscale, Zscale, Angle, Sin, Cos float64
}

var set *SurfaceSet

func CurrentSet() *SurfaceSet {
	if set == nil {
		set = new(SurfaceSet)
		set.Height = 320
		set.Width = 600
		set.Cells = 100
		set.Xyrange = 30.0
		set.Color = 0x808080
		set.Angle = math.Pi / 6
	}

	set.SetComplete()
	return set
}

func (set *SurfaceSet) SetComplete() {
	set.Xyscale = 10.0
	set.Zscale = 128.0
	set.Sin = math.Sin(set.Angle)
	set.Cos = math.Cos(set.Angle)

	fmt.Printf("SurfaceSet is Done. Current is %v.\n", utils.DumpStruct(set))
}

func cornerCustomized(c CalcZ, i, j int) (float64, float64, error) {
	// Find point (x,y) at corner of cell(i,j)
	x := set.Xyrange * (float64(i)/float64(set.Cells) - 0.5)
	y := set.Xyrange * (float64(j)/float64(set.Cells) - 0.5)

	// Compute surface height z
	z := c(x, y)

	if math.IsNaN(z) {
		return 0, 0, NaN{}
	}

	if math.IsInf(z, 0) {
		return 0, 0, Inf{}
	}

	// Project (x,y,z) isometrically onto 2-D SVG canvas (sx, sy)
	sx := float64(set.Width/2) + (x-y)*set.Cos*set.Xyscale
	sy := float64(set.Height/2) + (x+y)*set.Sin*set.Xyscale - z*set.Zscale
	return sx, sy, nil
}

func SurfaceIOCustomized(c CalcZ, out io.Writer) {
	fmt.Fprintf(out, "<svg xmlns='http://www.w3.org/2000/svg' "+
		"style='stroke: #%x; fill: white; stroke-width: 0.7' "+
		"width='%d' height='%d'>", set.Color, set.Width, set.Height)

	for i := 0; i < set.Cells; i++ {
		for j := 0; j < set.Cells; j++ {
			var err error
			var ax, ay, bx, by, cx, cy, dx, dy float64
			if ax, ay, err = cornerCustomized(c, i+1, j); err != nil {
				continue
			}
			if bx, by, err = cornerCustomized(c, i, j); err != nil {
				continue
			}
			if cx, cy, err = cornerCustomized(c, i, j+1); err != nil {
				continue
			}
			if dx, dy, err = cornerCustomized(c, i+1, j+1); err != nil {
				continue
			}

			fmt.Fprintf(out, "<polygon points='%g,%g %g,%g %g,%g %g,%g'/>\n",
				ax, ay, bx, by, cx, cy, dx, dy)
		}
	}

	fmt.Fprintf(out, "</svg>\n")
}
