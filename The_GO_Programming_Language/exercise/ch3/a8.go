package main

import (
	"fmt"
	"net/http"
	"tgpl/mandelbrot"
	"tgpl/server"
)

func handleMandelbrot(w http.ResponseWriter, r *http.Request) {
	if err := server.ParseForm(r, mandelbrot.CurrentSet()); err != nil {
		fmt.Printf("ParseForm err: %v.\n", err)
	}
	mandelbrot.Mandelbrot(w)
}

// /mandelbrot?style=colorful&supersampling=true&method=newton&x=0.99&y=0.99&zoom=100
func main() {
	server.Server(map[string]server.Handler{"/mandelbrot": handleMandelbrot})
}
