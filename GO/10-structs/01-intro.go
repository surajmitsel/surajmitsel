package main

import "fmt"

type Product struct {
	id   int
	name string
	cost float32
}

func main() {
	/*
		var product struct {
			id   int
			name string
			cost float32
		} = struct {
			id   int
			name string
			cost float32
		}{
			id:   100,
			name: "Pen",
			cost: 10,
		}
	*/

	// var product Product
	// var product Product = Product{100, "Pen", 10} //=> NOT PREFERRED

	var product Product = Product{
		id:   100,
		name: "Pen",
		cost: 10,
	}

	// fmt.Println(product)
	// fmt.Printf("%#v\n", product)
	fmt.Printf("%+v\n", product)

	fmt.Println("Accessing the fields")
	display(product)

	fmt.Println("After applying 10% discount")
	applyDiscount(&product, 10)
	display(product)
	/*
		p1 := Product{id: 999, name: "dummy", cost: 1000.99}
		// p2 := Product{id: 999, name: "dummy", cost: 1000.99}
		p2 := p1              //creating a COPY
		fmt.Println(p1 == p2) // EVERYTHING is a VALUE in go

		p2.cost = 888
		fmt.Println(p1)
		fmt.Println(p2)
	*/

	//pointer to an instance
	// productPtr := &Product{}
	productPtr := new(Product)
	fmt.Println(productPtr)

}

func display(product Product) {
	fmt.Printf("Id = %d, Name = %q, Cost = %0.2f\n", product.id, product.name, product.cost)
}

func applyDiscount(product *Product, discountPercentage float32) {
	product.cost = product.cost * ((100 - discountPercentage) / 100)
	// (*product).cost = (*product).cost * ((100 - discountPercentage) / 100)
}
