/* Write a function that returns all the prime numbers beween the given start and end
print the generated prime numbers in the main function
*/

package main

import "fmt"

func main() {
	primeNos := generatePrimes(2, 100)
	fmt.Println(primeNos)
}

func generatePrimes(start, end int) []int {
	primeNos := make([]int, 0)
	for i := start; i <= end; i++ {
		if isPrime(i) {
			primeNos = append(primeNos, i)
		}
	}
	return primeNos
}

func isPrime(no int) bool {
	for i := 2; i <= (no / 2); i++ {
		if no%i == 0 {
			return false
		}
	}
	return true
}
