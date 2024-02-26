package main

import (
	"fmt"
	"sync"
)

type Counter struct {
	sync.Mutex
	count int
}

func (c *Counter) increment() {
	c.Lock()
	{
		c.count++
	}
	c.Unlock()
}

func main() {
	var counter Counter
	wg := &sync.WaitGroup{}
	for i := 0; i < 200; i++ {
		wg.Add(1)
		go func() {
			counter.increment()
			wg.Done()
		}()
	}
	wg.Wait()
	fmt.Println(counter.count)
}
