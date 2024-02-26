package main

import "fmt"

func main() {
	// var nos [5]int // memory is allocated & initialized (with default value of int - 0)
	var nos [5]int = [5]int{3, 1, 4, 2, 5}
	// var nos [5]int = [5]int{3, 1, 4}

	// type inference
	// var nos = [5]int{3, 1, 4}
	// nos := [5]int{3, 1, 4}
	fmt.Println(nos) // [3 1 4 2 5]

	fmt.Println()
	fmt.Println("Iterating an array [using indexer]")
	for i := 0; i < 5; i++ {
		fmt.Printf("nos[%d] = %d\n", i, nos[i])
	}
	// nos[0] = 3
	// nos[1] = 1
	// nos[2] = 4
	// nos[3] = 2
	// nos[4] = 5

	fmt.Println() // [3 1 4 2 5]
	fmt.Println("Iterating an array [using range]")
	for idx, val := range nos {
		fmt.Printf("nos[%d] = %d\n", idx, val)
	}

	// nos[0] = 3
	// nos[1] = 1
	// nos[2] = 4
	// nos[3] = 2
	// nos[4] = 5

	sort(&nos)
	fmt.Println(nos) // [1 2 3 4 5]

	x := [5]int{3, 1, 4, 2, 5}
	y := [5]int{3, 1, 4, 2, 5}
	fmt.Printf("&x = %p\n", &x) // &x = 0xc00001a0c0
	fmt.Printf("&y = %p\n", &y) // &y = 0xc00001a0f0
	fmt.Println(x == y) // true

}

/* write sort fn to sort an array of 5 integers (bubble sort) */
func sort(x *[5]int) {
	for i := 0; i < 4; i++ {
		for j := i + 1; j < 5; j++ {
			if x[i] > x[j] {
				x[i], x[j] = x[j], x[i]
			}
		}
	}
}
