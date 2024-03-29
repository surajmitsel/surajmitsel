package main

import "fmt"

func main() {
	/*
		const red int = 0
		const green int = 1
		const blue int = 2
	*/

	/*
		const (
			red   int = iota
			green int = iota
			blue  int = iota
		)
	*/

	/*
		const (
			red   int = iota
			green     = iota
			blue      = iota
		)
	*/
	/*
		const (
			red int = iota
			green
			blue
		)
	*/

	/*
		const (
			red = iota + 2
			green
			blue
		)
	*/

	/*
		const (
			red = iota * 2
			green
			blue
		)
	*/

	const (
		red = iota * 2
		green
		_
		blue
	)
	fmt.Printf("Red = %d, Greent = %d and Blue = %d\n", red, green, blue)

	fmt.Println("iota applied")
	const (
		VERBOSE = 1 << iota
		CONFIG_FROM_DISK
		DATABASE_REQUIRED
		LOGGER_ACTIVATED
		DEBUG
		FLOAT_SUPPORT
		RECOVERY_MODE
		REBOOT_ON_FAILURE
	)
	// fmt.Printf("%b, %b, %b, %b, %b, %b, %b, %b\n", VERBOSE, CONFIG_FROM_DISK, DATABASE_REQUIRED, LOGGER_ACTIVATED, DEBUG, FLOAT_SUPPORT, RECOVERY_MODE, REBOOT_ON_FAILURE)
	fmt.Printf("%d, %d, %d, %d, %d, %d, %d, %d\n", VERBOSE, CONFIG_FROM_DISK, DATABASE_REQUIRED, LOGGER_ACTIVATED, DEBUG, FLOAT_SUPPORT, RECOVERY_MODE, REBOOT_ON_FAILURE)
}
