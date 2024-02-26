package main

import "fmt"

func main() {
	// no parameter, no return values
	sayHi()

	// 1 parameter
	greet("Magesh")

	// 1 parameter & 1 return value
	greetMsg := getGreetMsg("Suresh")
	fmt.Println(greetMsg)

	// more than 1 parameter & 1 return value
	fmt.Println(add(100, 200))

	// more than 1 return results
	// fmt.Println(divide(100, 7))

	/*
		q, r := divide(100, 7)
		fmt.Printf("Dividing 100 by 7, quotient = %d and remainder = %d\n", q, r)
	*/

	// using ONLY the quotient
	q, _ := divide(100, 7)
	fmt.Printf("Dividing 100 by 7, quotient = %d\n", q)
}

func sayHi() {
	fmt.Println("Hi!")
}

func greet(userName string) {
	fmt.Printf("Hi %s, Have a nice day!\n", userName)
}

func getGreetMsg(userName string) string {
	return fmt.Sprintf("Hi %s, Have a good day!", userName)
}

/*
func add(x int, y int) int {
	return x + y
}
*/

func add(x, y int) int {
	return x + y
}

/*
func divide(x, y int) (int, int) {
	quotient := x / y
	remainder := x % y
	return quotient, remainder
}
*/

// named result
/*
func divide(x, y int) (quotient, remainder int) {
	quotient = x / y
	remainder = x % y
	return
}
*/

func divide(x, y int) (quotient, remainder int) {
	quotient, remainder = x/y, x%y
	return
}
