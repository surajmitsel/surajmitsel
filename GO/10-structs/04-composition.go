package main

import "fmt"

type Product struct {
	Id   int
	Name string
	Cost float32
}

type Dummy struct {
	Name string
}

type PerishableProduct struct {
	Product
	/*
		Dummy
		Name   string
	*/
	Expiry string
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
	// grapes := PerishableProduct{Product{100, "Grapes", 50}, "2 Days"}
	/*
		grapes := PerishableProduct{
			Product: Product{
				Id:   100,
				Name: "Grapes",
				Cost: 50,
			},
			Expiry: "2 Days",
		}
	*/
	grapes := NewPerishableProduct(100, "Grapes", 50, "2 Days")
	fmt.Printf("%+v\n", grapes)
	// fmt.Println(grapes.Product.Name)
	// fmt.Println(grapes.Dummy.Name)
	fmt.Println(grapes.Name)
}
