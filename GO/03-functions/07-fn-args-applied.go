package main

import (
	"fmt"
)

func main() {
	/*
		add(100, 200)
		subtract(100, 200)
	*/

	/*
		fmt.Println("Operation started")
		add(100, 200)
		fmt.Println("Operation completed")

		fmt.Println("Operation started")
		subtract(100, 200)
		fmt.Println("Operation completed")
	*/

	/*
		logAdd(100, 200)
		logSubtract(100, 200)
	*/

	logOperation(add, 100, 200)
	logOperation(subtract, 100, 200)
	logOperation(func(x, y int) {
		fmt.Println("Multiply Result :", x*y)
	}, 100, 200)

}

func logOperation(fn func(int, int), x, y int) {
	fmt.Println("Operation started")
	fn(x, y)
	fmt.Println("Operation completed")
}

/*
func logAdd(x, y int) {
	fmt.Println("Operation started")
	add(x, y)
	fmt.Println("Operation completed")
}

func logSubtract(x, y int) {
	fmt.Println("Operation started")
	subtract(x, y)
	fmt.Println("Operation completed")
}
*/

//3rd party library
func add(x, y int) {
	fmt.Println("Add Result : ", x+y)
}

func subtract(x, y int) {
	fmt.Println("Subtract Result : ", x-y)
}
