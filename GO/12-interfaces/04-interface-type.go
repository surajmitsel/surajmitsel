package main

import (
	"fmt"
	"math"
)

type Circle struct {
	Radius float32
}

func (c Circle) Area() float32 {
	return math.Pi * c.Radius * c.Radius
}

func (c Circle) Perimeter() float32 {
	return 2 * math.Pi * c.Radius
}

type Rectangle struct {
	Length  float32
	Breadth float32
}

func (r Rectangle) Area() float32 {
	return r.Length * r.Breadth
}

func (r Rectangle) Perimeter() float32 {
	return 2 * (r.Length + r.Breadth)
}

/*
func PrintArea(x interface{}) {
	switch obj := x.(type) {
	case Circle:
		fmt.Println("Area :", obj.Area())
	case Rectangle:
		fmt.Println("Area :", obj.Area())
	}
}
*/
type AreaFinder interface {
	Area() float32
}

func PrintArea(x AreaFinder) {
	fmt.Println("Area :", x.Area())
}

type PerimeterFinder interface {
	Perimeter() float32
}

func PrintPerimeter(x PerimeterFinder) {
	fmt.Println("Perimeter :", x.Perimeter())
}

type StatsFinder interface {
	AreaFinder
	PerimeterFinder
}

func PrintStats(x StatsFinder) {
	PrintArea(x)
	PrintPerimeter(x)
}

func main() {
	c := Circle{Radius: 12}
	// fmt.Println("Area :", c.Area())
	/*
		PrintArea(c)
		PrintPerimeter(c)
	*/
	PrintStats(c)

	r := Rectangle{Length: 10, Breadth: 12}
	// fmt.Println("Area :", r.Area())
	/*
		PrintArea(r)
		PrintPerimeter(r)
	*/
	PrintStats(r)

	// PrintArea(100)
}
