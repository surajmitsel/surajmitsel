package calculator

import "fmt"

//private
var operationCount map[string]int

func init() {
	fmt.Println("calculator - calc.go initialized")
	operationCount = make(map[string]int)
}

//public accessor
func OpCount() map[string]int {
	return operationCount
}
