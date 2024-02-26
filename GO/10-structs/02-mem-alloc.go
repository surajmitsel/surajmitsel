package main

import "fmt"

type Product struct {
	id   int
	name string
	cost float32
}

// var p Product = Product{100, "Pen", 10}

func main() {
	p := Product{100, "Pen", 10}
	p.cost = 100
	fmt.Println(p)
}
