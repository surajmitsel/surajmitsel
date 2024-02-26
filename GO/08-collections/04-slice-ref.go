package main

import "fmt"

func main() {
	nos := []int{3, 1, 4, 2, 5}
	sort(nos)
	fmt.Println(nos)

	/*
		// slices cannot be compared
		nos2 := []int{3, 1, 4, 2, 5}
		fmt.Println(nos == nos2)
	*/

	// creating a copy of the slice
	nosCopy := make([]int, len(nos))
	copy(nosCopy, nos)

	nosCopy[0] = 9999
	fmt.Println("nosCopy =", nosCopy)
	fmt.Println("nos =", nos)
}

func sort(x []int) {
	for i := 0; i < 4; i++ {
		for j := i + 1; j < 5; j++ {
			if x[i] > x[j] {
				x[i], x[j] = x[j], x[i]
			}
		}
	}
}
