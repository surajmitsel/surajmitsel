package main

import "fmt"

func main() {
	ch := make(chan int)
	go func() {
		ch <- 100 // since a receive operation is already initiated (line : 10), this will be a NON-BLOCKing operation
	}()
	data := <-ch //channel receive operation initiated, but blocked coz there is no data
	fmt.Println(data)
}
