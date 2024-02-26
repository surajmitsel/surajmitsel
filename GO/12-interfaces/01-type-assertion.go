package main

import "fmt"

func main() {
	// var x interface{}
	var x any
	x = 100
	x = true
	x = "Ut consequat mollit magna deserunt minim enim. Nisi velit minim consectetur sit excepteur non enim est esse irure et. Qui occaecat cillum consectetur tempor officia aute occaecat Lorem ullamco. Elit qui dolor nisi veniam esse. Cupidatat anim fugiat aute elit amet officia labore velit aliqua elit officia. Non quis est laboris quis eiusmod officia esse reprehenderit sunt exercitation et. Sint voluptate esse et ea do velit tempor ut laborum nostrud sunt."
	x = 99.99
	x = struct{}{}
	fmt.Println(x)

	// type assertion using "if"
	x = 100
	// x = "This is a string"
	// y := x.(int) + 200
	if val, ok := x.(int); ok {
		y := val + 200
		fmt.Println(y)
	} else {
		fmt.Println("x is not an int")
	}

	// type assertion using "switch"
	// x = true
	// x = "Anim reprehenderit ullamco ea elit ad aliquip exercitation duis ullamco do qui in. Irure exercitation in culpa consequat cillum in minim excepteur ullamco nostrud velit. Duis anim amet officia nostrud aliquip velit in deserunt eiusmod minim. In fugiat amet culpa qui ipsum deserunt aliqua enim incididunt sunt. Velit qui ex aliquip ad proident deserunt mollit magna aute mollit velit. Laboris et eiusmod in voluptate dolor."
	// x = 8.987
	// x = struct{}{}
	x = 14 + 15i
	switch val := x.(type) {
	case int:
		fmt.Println("x is an int, x + 200 =", val+200)
	case bool:
		fmt.Println("x is a bool, !x = ", !val)
	case string:
		fmt.Println("x is a string, len(x) =", len(val))
	case float64:
		fmt.Println("x is a float64, 99.99% of x =", val*0.9999)
	case struct{}:
		fmt.Println("x is an empty struct")
	default:
		fmt.Println("x is an unknown type")
	}

}
