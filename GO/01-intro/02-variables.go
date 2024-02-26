package main

import "fmt"

var x = 100

func main() {
	/*
		var name string
		name = "Magesh"
		fmt.Printf("Hi %s!\n", name)
	*/

	/*
		var name string = "Magesh"
		fmt.Printf("Hi %s!\n", name)
	*/

	//type inference
	/*
		var name = "Magesh"
		fmt.Printf("Hi %s!\n", name)
	*/

	name := "Magesh"
	fmt.Printf("Hi %s!\n", name)
	fmt.Println(len(name))

	// Using multiple variables
	/*
		var x int
		var y int
		var result int
		var str string
		x = 100
		y = 200
		result = x + y
		str = "Sum of %d and %d is %d\n"
		fmt.Printf(str, x, y, result)
	*/

	/*
		var x, y, result int
		var str string
		x = 100
		y = 200
		result = x + y
		str = "Sum of %d and %d is %d\n"
		fmt.Printf(str, x, y, result)
	*/

	/*
		var (
			x, y, result int
			str          string
		)
		x = 100
		y = 200
		result = x + y
		str = "Sum of %d and %d is %d\n"
		fmt.Printf(str, x, y, result)
	*/

	/*
		var x int = 100
		var y int = 200
		var result int = x + y
		var str string = "Sum of %d and %d is %d\n"
		fmt.Printf(str, x, y, result)
	*/

	/*
		var x, y int = 100, 200
		var result int = x + y
		var str string = "Sum of %d and %d is %d\n"
		fmt.Printf(str, x, y, result)
	*/

	/*
		var (
			x, y   int    = 100, 200
			result int    = x + y
			str    string = "Sum of %d and %d is %d\n"
		)
		fmt.Printf(str, x, y, result)
	*/

	/*
		var (
			x, y   = 100, 200
			result = x + y
			str    = "Sum of %d and %d is %d\n"
		)
		fmt.Printf(str, x, y, result)
	*/

	/*
		var (
			x, y, str = 100, 200, "Sum of %d and %d is %d\n"
			result    = x + y
		)
		fmt.Printf(str, x, y, result)
	*/

	x, y, str := 100, 200, "Sum of %d and %d is %d\n"
	result := x + y
	fmt.Printf(str, x, y, result)

}
