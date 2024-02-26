package main

import "fmt"

type Product struct {
	Id   int
	Name string
	Cost float32
}

func (p Product) Format() string {
	return fmt.Sprintf("Id = %d, Name = %q, Cost = %0.2f", p.Id, p.Name, p.Cost)
}

func (p *Product) ApplyDiscount(discount float32) {
	p.Cost = p.Cost * ((100 - discount) / 100)
}

func main() {
	pen := Product{
		Id:   100,
		Name: "Pen",
		Cost: 5,
	}
	/*
		pen := &Product{
			Id:   100,
			Name: "Pen",
			Cost: 5,
		}
	*/
	// fmt.Println(Format(pen))
	fmt.Println(pen.Format())

	fmt.Println("After applying 10% discount")
	// ApplyDiscount(&pen, 10)
	// (&pen).ApplyDiscount(10)
	pen.ApplyDiscount(10)

	// fmt.Println(Format(pen))
	fmt.Println(pen.Format())
}
