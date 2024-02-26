package main

import "fmt"

func main() {
	var c1 complex128 = 12 + 13i
	fmt.Println(c1)
	// var c2 complex128 = 17 + 12i
	// var c2 = 17 + 12i
	c2 := 17 + 12i
	var result = c1 + c2
	fmt.Println(c2)
	fmt.Println(result)

	fmt.Println("real : ", real(result))
	fmt.Println("imaginary : ", imag(result))
}
