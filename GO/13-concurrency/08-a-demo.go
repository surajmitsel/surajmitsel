package main

import (
	"fmt"
	"sync"
)

//Share memory by communicating

func main() {
	wg := &sync.WaitGroup{}
	ch := make(chan int)
	wg.Add(1)
	go add(100, 200, wg, ch)
	result := <-ch
	wg.Wait() // blocked
	fmt.Println(result)
}

func add(x, y int, wg *sync.WaitGroup, ch chan int) {
	result := x + y
	ch <- result //non-blocking
	wg.Done()
}
