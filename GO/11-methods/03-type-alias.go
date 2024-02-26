package main

import "fmt"

type MyStr string

func (s MyStr) Length() int {
	return len(s)
}

func main() {
	s := MyStr("Amet esse consectetur eu sint laborum sit mollit cillum esse. Ad aute proident cillum et amet fugiat est consequat aliqua nisi officia veniam. Ad velit Lorem enim dolore consectetur sunt voluptate aliquip laborum commodo qui aliquip.")
	fmt.Println(s.Length())
}
