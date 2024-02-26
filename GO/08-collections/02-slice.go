package main

import "fmt"

func main() {
	// var nos []int
	// var nos []int = []int{3, 1, 4, 2, 5}
	// var nos = []int{3, 1, 4, 2, 5}
	nos := []int{3, 1, 4, 2, 5}
	fmt.Println(nos)

	fmt.Println("len(nos) =", len(nos))

	fmt.Println()
	fmt.Println("Iterating a slice [using indexer]")
	for i := 0; i < len(nos); i++ {
		fmt.Printf("nos[%d] = %d\n", i, nos[i])
	}

	fmt.Println()
	fmt.Println("Iterating a slice [using range]")
	for idx, val := range nos {
		fmt.Printf("nos[%d] = %d\n", idx, val)
	}

	fmt.Println("Appending new values")
	nos = append(nos, 10)
	fmt.Println(nos)
	nos = append(nos, 20, 30)
	fmt.Println(nos)

	fmt.Println("Appending another slice")
	hundreds := []int{100, 200, 300}
	nos = append(nos, hundreds...)
	fmt.Println(nos)

	fmt.Println("Slicing")
	fmt.Println("nos[2:5] =", nos[2:5])
	fmt.Println("nos[2:] =", nos[2:])
	fmt.Println("nos[:5] =", nos[:5])

	subset := nos[2:5]
	fmt.Println("subset =", subset)
	subset[0] = 9999
	fmt.Println("After changing subset")
	fmt.Println("subset =", subset)
	fmt.Println("nos =", nos)

	fmt.Println("len(subset) =", len(subset))
	fmt.Println("subset[5] =", subset[5])

}
