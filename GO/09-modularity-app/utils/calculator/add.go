package calculator

import "fmt"

func init() {
	fmt.Println("calculator-add initialized")
}

func Add(x, y int) int {
	operationCount["add"]++
	return x + y
}
