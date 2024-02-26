package main

import "fmt"

func main() {
	// var productRanks map[string]int = map[string]int{"pen": 1, "pencil": 4}
	/*
		var productRanks map[string]int = map[string]int{
			"pen":    1,
			"pencil": 4,
		}
	*/

	/*
		var productRanks = map[string]int{
			"pen":    1,
			"pencil": 4,
		}
	*/

	/*
		productRanks := map[string]int{
			"pen":    1,
			"pencil": 4,
		}
	*/
	// productRanks := map[string]int{}
	productRanks := make(map[string]int)
	productRanks["pen"] = 4
	productRanks["pencil"] = 1
	productRanks["marker"] = 2
	productRanks["notepad"] = 3
	fmt.Println(productRanks)

	fmt.Println("Rank of pen = ", productRanks["pen"])

	fmt.Println("# of items in productRanks = ", len(productRanks))

	fmt.Println("Iterating a map")
	for key, val := range productRanks {
		fmt.Printf("productsRanks[%q] = %d\n", key, val)
	}

	nonExistentKey := "stapler"
	/*
		exists, val := productRanks[nonExistentKey]
		fmt.Println("productRanks[stapler] = ", val, exists)
	*/

	fmt.Println("productRanks[stapler] = ", productRanks[nonExistentKey])

	fmt.Println("Check for the existence of a key")
	keyToCheck := "stapler"
	if val, exists := productRanks[keyToCheck]; exists {
		fmt.Printf("Value of %q is %d\n", keyToCheck, val)
	} else {
		fmt.Printf("Key %q doesnot exist\n", keyToCheck)
	}

	fmt.Println("Deleting a key/value pair")
	// keyToDelete := "pen"
	keyToDelete := "stapler"
	delete(productRanks, keyToDelete)
	fmt.Printf("After deleting %q, productRanks = %v\n", keyToDelete, productRanks)
}
