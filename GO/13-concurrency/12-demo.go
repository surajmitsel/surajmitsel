package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(35)
	ch := make(chan int)
	go generateNumbers(ch)
	for {
		if data, isOpen := <-ch; isOpen {
			time.Sleep(500 * time.Millisecond)
			fmt.Println(data)
		} else /* channel is closed */ {
			break
		}
	}
}

func generateNumbers(ch chan int) {
	// count := rand.Intn(20)
	count := 15
	fmt.Printf("count = %d\n", count)
	for i := 1; i <= count; i++ {
		ch <- i * 10
	}
	close(ch)
	fmt.Println("All data generated")
}
