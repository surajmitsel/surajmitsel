package calculator

import "fmt"

func init() {
	fmt.Println("calculator-subtract initialized")
}

func Subtract(x, y int) int {
	operationCount["subtract"]++
	return x - y
}
