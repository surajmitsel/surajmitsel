package main

import "fmt"

type Product struct {
	Id   int
	Name string
	Cost float32
}

/* fmt.Stringer implementation */
func (p Product) String() string {
	return fmt.Sprintf("Id = %d, Name = %q, Cost = %0.2f", p.Id, p.Name, p.Cost)
}

func (p *Product) ApplyDiscount(discount float32) {
	p.Cost = p.Cost * ((100 - discount) / 100)
}

type PerishableProduct struct {
	Product
	Expiry string
}

// fmt.Stringer implementation
func (pp PerishableProduct) String() string {
	return fmt.Sprintf("%s, Expiry = %q", pp.Product, pp.Expiry)
}

func NewPerishableProduct(id int, name string, cost float32, expiry string) *PerishableProduct {
	return &PerishableProduct{
		Product: Product{
			Id:   id,
			Name: name,
			Cost: cost,
		},
		Expiry: expiry,
	}
}

func main() {

	grapes := NewPerishableProduct(100, "Grapes", 50, "2 Days")

	fmt.Println(grapes)
	grapes.ApplyDiscount(20)
	fmt.Println("After applying 20% discount")
	fmt.Println(grapes)
}
