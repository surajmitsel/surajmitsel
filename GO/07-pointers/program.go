package main

import "fmt"

func main() {
	var x int = 100
	var xPtr *int
	xPtr = &x // value -> address
	fmt.Println(xPtr)

	// deferencing (address -> value)
	var val = *xPtr
	fmt.Println(val)

	fmt.Println(x == *(&x))

	fmt.Println("Before incrementing, x =", x)
	increment(&x)
	fmt.Println("After incrementing, x =", x)

	n1, n2 := 10, 20
	fmt.Printf("Before swapping, n1 = %d and n2 = %d\n", n1, n2)
	swap(&n1, &n2)
	fmt.Printf("After swapping, n1 = %d and n2 = %d\n", n1, n2)
}

func increment(no *int) {
	fmt.Println("[increment] &no = ", no)
	*no++
}

func swap(x, y *int) /* no return values */ {
	*x, *y = *y, *x
}
