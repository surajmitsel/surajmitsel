package main

import (
	"fmt"
	"time"
)

func main() {
	// panic("dummy panic")
	fmt.Println("main started")
	go f1() //schedule this function to be executed by the scheduler IN FUTURE
	f2()

	/* Poor man's logic of synchronizing goroutines */

	time.Sleep(5 * time.Second) // block the main function and there by giving the opportunity for the scheduler to go and look for other scheduled goroutines and execute them
	fmt.Scanln()
	fmt.Println("main completed")
}

func f1() {
	fmt.Println("	f1 started")
	time.Sleep(4 * time.Second)
	fmt.Println("	f1 completed")
}

func f2() {
	fmt.Println("f2 invoked")
}
