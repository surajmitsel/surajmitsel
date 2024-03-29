package main

import (
	"fmt"
	"sync"
)

//communicate by sharing memory (NOT ADVISABLE)
/*
var result int

func main() {
	wg := &sync.WaitGroup{}
	wg.Add(1)
	go add(100, 200, wg)
	wg.Wait()
	fmt.Println(result)
}

func add(x, y int, wg *sync.WaitGroup) {
	defer wg.Done()
	result = x + y
}
*/

func main() {
	wg := &sync.WaitGroup{}
	var result int
	wg.Add(1)
	go add(100, 200, wg, &result)
	wg.Wait()
	fmt.Println(result)
}

func add(x, y int, wg *sync.WaitGroup, result *int) {
	defer wg.Done()
	*result = x + y
}
