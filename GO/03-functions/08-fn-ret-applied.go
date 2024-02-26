package main

import (
	"fmt"
	"time"
)

func main() {
	// logging
	/*
		logAdd := getLogOperation(add)
		logAdd(100, 200)

		logSubtract := getLogOperation(subtract)
		logSubtract(100, 200)
	*/

	// profiling
	/*
		profileAdd := getProfileOperation(add)
		profileAdd(100, 200)

		profileSubtract := getProfileOperation(subtract)
		profileSubtract(100, 200)
	*/

	// profiling & logging
	logAdd := getLogOperation(add)
	profileLogAdd := getProfileOperation(logAdd)
	profileLogAdd(100, 200)

	getProfileOperation(getLogOperation(subtract))(100, 200)
}

func getLogOperation(fn func(int, int)) func(int, int) {
	return func(x, y int) {
		fmt.Println("Operation started")
		fn(x, y)
		fmt.Println("Operation completed")
	}
}

func getProfileOperation(fn func(int, int)) func(int, int) {
	return func(x, y int) {
		start := time.Now()
		fn(x, y)
		elapsed := time.Since(start)
		fmt.Println("Elapsed :", elapsed)
	}
}

//3rd party library
func add(x, y int) {
	fmt.Println("Add Result : ", x+y)
}

func subtract(x, y int) {
	fmt.Println("Subtract Result : ", x-y)
}
