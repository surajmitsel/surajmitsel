package main

import (
	"errors"
	"fmt"
)

/*
	2 ways to create an error
		- using fmt.Errorf()
		- using errors.New()
*/

var DivideByZeroError error = errors.New("divisor cannot be 0")

func main() {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println("Something went wrong. ", err)
			return
		}
		fmt.Println("App successfully executed. Thank you!")
	}()
	divisor := 0
	q, r, err := divideClient(100, divisor)
	if err != nil {
		fmt.Println("input error. handle it.")
	} else {
		fmt.Printf("Dividing 100 by %d, quotient = %d and remainder = %d\n", divisor, q, r)
	}

	panic("main is not right")
}

func divideClient(x, y int) (quotient, remainder int, err error) {
	defer func() {
		if er, ok := recover().(error); ok {
			err = er
		}
	}()
	quotient, remainder = divide(x, y)
	/*
		file, err := os.Open("data.txt")
		if err != nil {
			//log the error
			return
		}

		// defer file.Close()
		defer func() {
			file.Close()
		}()
	*/
	return
}

//3rd party api
func divide(x, y int) (quotient, remainder int) {
	fmt.Println("Calculating quotient")
	if y == 0 {
		panic(DivideByZeroError)
	}

	quotient = x / y
	fmt.Println("Calculating remainder")
	remainder = x % y
	return
}
