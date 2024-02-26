package main

import "fmt"

func main() {
	/*
		const pi float32 = 3.14
		// type inference
		const app_version = "1.0.0"
	*/

	const (
		pi          float32 = 3.14
		app_version         = "1.0.0"
	)

	fmt.Println(pi)
	fmt.Println(app_version)

	// unused constants - allowed
	const name = "Magesh"
}
