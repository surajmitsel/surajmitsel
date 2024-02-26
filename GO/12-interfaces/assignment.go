package main

import (
	"fmt"
	"sort"
	"strings"
)

type Product struct {
	Id       int
	Name     string
	Cost     float32
	Units    int
	Category string
}

func (p Product) String() string {
	return fmt.Sprintf("Id = %d, Name = %q, Cost = %.2f, Units = %d, Category = %q", p.Id, p.Name, p.Cost, p.Units, p.Category)
}

/*
	Implement Sort
		- User should be able to sort by any attribute
		- IMPORTANT : Must use sort.Sort()

		data interface
			Len() int
			Less(i,j int) bool
			Swap(i, j int)
*/

type Products []Product

func (products Products) String() string {
	var builder strings.Builder
	for _, p := range products {
		builder.WriteString(fmt.Sprintf("%s\n", p))
	}
	return builder.String()
}

/* sort.data interface implementation */
func (products Products) Len() int {
	return len(products)
}

func (products Products) Less(i, j int) bool {
	return products[i].Id < products[j].Id
}

func (products Products) Swap(i, j int) {
	products[i], products[j] = products[j], products[i]
}

// Sort by name
type ByName struct {
	Products
}

func (byName ByName) Less(i, j int) bool {
	return byName.Products[i].Name < byName.Products[j].Name
}

// Sort by Cost
type ByCost struct {
	Products
}

func (byCost ByCost) Less(i, j int) bool {
	return byCost.Products[i].Cost < byCost.Products[j].Cost
}

// Sort by Units
type ByUnits struct {
	Products
}

func (byUnits ByUnits) Less(i, j int) bool {
	return byUnits.Products[i].Units < byUnits.Products[j].Units
}

// Sort by Category
type ByCategory struct {
	Products
}

func (byCategory ByCategory) Less(i, j int) bool {
	return byCategory.Products[i].Category < byCategory.Products[j].Category
}

// utility method for sorting
func (products Products) Sort(attrName string) {
	switch attrName {
	case "Id":
		sort.Sort(products)
	case "Name":
		sort.Sort(ByName{products})
	case "Cost":
		sort.Sort(ByCost{products})
	case "Units":
		sort.Sort(ByUnits{products})
	case "Category":
		sort.Sort(ByCategory{products})
	}
}

// alternate implementation
func (products Products) SortSlice(attrName string) {
	switch attrName {
	case "Id":
		sort.Slice(products, func(i, j int) bool {
			return products[i].Id < products[j].Id
		})
	case "Name":
		sort.Slice(products, func(i, j int) bool {
			return products[i].Name < products[j].Name
		})
	case "Cost":
		sort.Slice(products, func(i, j int) bool {
			return products[i].Cost < products[j].Cost
		})
	case "Units":
		sort.Slice(products, func(i, j int) bool {
			return products[i].Units < products[j].Units
		})
	case "Category":
		sort.Slice(products, func(i, j int) bool {
			return products[i].Category < products[j].Category
		})
	}
}

func main() {
	products := Products{
		Product{105, "Pen", 5, 50, "Stationary"},
		Product{107, "Pencil", 2, 100, "Stationary"},
		Product{103, "Marker", 50, 20, "Utencil"},
		Product{102, "Stove", 5000, 5, "Utencil"},
		Product{101, "Kettle", 2500, 10, "Utencil"},
		Product{104, "Scribble Pad", 20, 20, "Stationary"},
		Product{109, "Golden Pen", 2000, 20, "Stationary"},
	}

	fmt.Println("Initial List")
	fmt.Println(products)

	fmt.Println("Default Sort (by id)")
	// sort.Sort(products)
	// products.Sort("Id")
	products.SortSlice("Id")
	fmt.Println(products)

	fmt.Println("Sort by Name")
	// sort.Sort(ByName{products})
	// products.Sort("Name")
	products.SortSlice("Name")
	fmt.Println(products)

	fmt.Println("Sort by Cost")
	// sort.Sort(ByCost{products})
	// products.Sort("Cost")
	products.SortSlice("Cost")
	fmt.Println(products)

	fmt.Println("Sort by Units")
	// sort.Sort(ByUnits{products})
	// products.Sort("Units")
	products.SortSlice("Units")
	fmt.Println(products)

	fmt.Println("Sort by Category")
	// sort.Sort(ByCategory{products})
	// products.Sort("Category")
	products.SortSlice("Category")
	fmt.Println(products)
}
