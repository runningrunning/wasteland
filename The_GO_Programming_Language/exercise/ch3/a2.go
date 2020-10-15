package main

import (
	"math"
	"net/http"
	"tgpl/server"
	"tgpl/surface"
)

// Todo Finish egg box, mogols, saddle

func calz_1(x, y float64) float64 {
	r := math.Hypot(x, y)
	return math.Sin(r) / r
}

func calz_2(x, y float64) float64 {
	o := math.Hypot(30, 30)
	r := math.Hypot(x, y)
	return -math.Sin(r / o * math.Pi * 2)
}

// egg box ?
func calz_3(x, y float64) float64 {
	return -math.Sqrt(15*15-x*x-y*y) / 15
}

func handlerSVG(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "image/svg+xml")
	surface.SurfaceIO(calz_3, w)
}

func main() {
	server.Server(map[string]server.Handler{"/surface": handlerSVG})
}
