package main

import (
	"fmt"
	"time"
)

func main() {
	stop := make(chan struct{})
	ch := genFib(stop)

	fmt.Println("Hit ENTER to stop....")
	go func() {
		fmt.Scanln()
		stop <- struct{}{}
	}()

	for no := range ch {
		fmt.Println(no)
	}
}

func genFib(stop <-chan struct{}) <-chan int {
	ch := make(chan int)
	go func() {
		x, y := 0, 1
	LOOP:
		for {
			select {
			case <-stop:
				fmt.Println("stop signal received")
				break LOOP
			default:
				time.Sleep(500 * time.Millisecond)
				ch <- x
				x, y = y, x+y
			}
		}
		close(ch)
	}()
	return ch
}
