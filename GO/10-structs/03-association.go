package main

import "fmt"

type Employee struct {
	Id     int
	Name   string
	Salary float32
	Org    *Organization
}

type Organization struct {
	Name string
	City string
}

func main() {
	orgCisco := &Organization{
		Name: "Cisco",
		City: "Bangalore",
	}

	e1 := Employee{
		Id:     100,
		Name:   "Magesh",
		Salary: 10000,
		Org:    orgCisco,
	}
	// fmt.Println(e1.Org.Name)

	e2 := Employee{
		Id:     101,
		Name:   "Suresh",
		Salary: 20000,
		Org:    orgCisco,
	}

	fmt.Println("e1.Org.City = ", e1.Org.City)
	fmt.Println("e2.Org.City = ", e2.Org.City)

	fmt.Println("Change Org City to Pune")
	orgCisco.City = "Pune"

	fmt.Println("e1.Org.City = ", e1.Org.City)
	fmt.Println("e2.Org.City = ", e2.Org.City)
}
