package main

import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan int)
	count := 10
	go generateNumbers(count, ch)
	for i := 0; i < count; i++ {
		fmt.Println(<-ch)
	}
}

func generateNumbers(count int, ch chan int) {
	for i := 1; i <= count; i++ {
		time.Sleep(500 * time.Millisecond)
		ch <- i * 10
	}
}
