#include <iostream>
using namespace std;

int swapBits_1(int val, int pos1, int pos2)
{
   #define TOGGLE(x,pos) ( x = x ^ (1 << pos))
   
   int x =  ((1 << pos1) & val) >> pos1;
   int y =  ((1 << pos2) & val) >> pos2;
   
   if(x != y){
      TOGGLE(val,pos1);
      TOGGLE(val,pos2);
   }
   return val;
}

// Function to swap bit positions at positions pos1 and pos2 in number n
unsigned int swapBits_2(unsigned int n, unsigned int pos1, unsigned int pos2) {
    // Extract bits at positions pos1 and pos2
    unsigned int bit1 = (n >> pos1) & 1;
    unsigned int bit2 = (n >> pos2) & 1;

    // XOR the bits to swap them (0 ^ 1 = 1, 1 ^ 0 = 1, 0 ^ 0 = 0, 1 ^ 1 = 0)
    if(bit1 != bit2){
        n ^= (bit1 << pos2) | (bit2 << pos1);
    }
    return n;
}

int main() {
    unsigned int num = 0b101010; // Binary representation of number 42
    unsigned int pos1 = 1;
    unsigned int pos2 = 4;

    std::cout << "Original number: " << num << std::endl;
    num = swapBits_1(num, pos1, pos2);
    std::cout << "Number after swapping bits at positions " << pos1 << " and " << pos2 << ": " << num << std::endl;

    printf("0x%X", swapBits_1(0xF2, 1, 3));

    return 0;
}
