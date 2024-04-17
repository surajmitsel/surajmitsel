#include <iostream>
using namespace std;

unsigned int swapConsecutiveBits(unsigned int num) {
    // Apply masks to swap consecutive bits
    unsigned int evenBits = num & 0xAAAA;  // Extract even bits
    unsigned int oddBits = num & 0x5555;   // Extract odd bits
    
    evenBits = evenBits >> 1;  // Shift even bits to the right
    oddBits = oddBits << 1;   // Shift odd bits to the left
    
    return (evenBits | oddBits);  // Combine even and odd bits
}

int main() {
    unsigned int num = 0b10101010; // Example number: 10101010 (in binary)
    cout << "Original number: " << bitset<8>(num) << endl;

    unsigned int swapped = swapConsecutiveBits(num);
    cout << "Number after swapping consecutive bits: " << bitset<8>(swapped) << endl;

    return 0;
}
