package main

import (
	"fmt"

	"github.com/fatih/color"
	myutils "github.com/tkmagesh/cisco-go-apr-2023/09-modularity-app/utils"
	"github.com/tkmagesh/cisco-go-apr-2023/09-modularity-app/utils/calculator"
)

func main() {
	// fmt.Println("app executed")
	color.Red("app executed")
	fmt.Println(myutils.IsEven(10))
	fmt.Println(myutils.IsOdd(10))
	fmt.Println(calculator.Add(100, 200))
	fmt.Println(calculator.Subtract(100, 200))
	fmt.Println(calculator.OpCount())
}
