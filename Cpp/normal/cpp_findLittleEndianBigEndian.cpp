#include <iostream>

// Macro to determine endianness
unsigned int endianTest = 1;
#define IS_LITTLE_ENDIAN (*(unsigned char *)&endianTest)

//#define IS_LITTLE_ENDIAN (*(unsigned char *)&(unsigned int)(1))
//without global variable some compiler gives error: cannot take the address of an rvalue of type 'unsigned int'

void checkEndian_1() {
    union {
        uint32_t i;
        char c[sizeof(uint32_t)];
    } test;

    test.i = 1; // Set the integer to a value where only the lowest byte has a non-zero value

    if (test.c[0] == 1) {
        std::cout << "Little endian" << std::endl;
    } else {
        std::cout << "Big endian" << std::endl;
    }
}

void checkEndian_2() {
    unsigned int num = 1;  // Initialize an integer with a value where only the lowest byte is non-zero.
    char *c = (char *)&num;  // Cast the address of num to a char pointer.

    if (*c) {
        printf("Little endian\n");  // If the first byte is 1, it's little endian.
    } else {
        printf("Big endian\n");  // Otherwise, it's big endian.
    }
}

int main() {
    checkEndian_1();
    checkEndian_2();

    if(IS_LITTLE_ENDIAN){
        printf("Little endian\n");  // If the first byte is 1, it's little endian.
    } else {
        printf("Big endian\n");  // Otherwise, it's big endian.
    }
    return 0;
}
