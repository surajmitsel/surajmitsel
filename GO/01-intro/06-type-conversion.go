package main

import "fmt"

func main() {
	var i int32 = 100
	var f float32
	// type conversion syntax - treat the typename like a function
	f = float32(i)
	fmt.Println(f)
}
