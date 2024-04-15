#include <stdint.h>
/*
htonl() (host to network long) and htons() (host to network short) convert 32-bit and 16-bit integers, respectively, 
from the host's byte order to network byte order (big-endian).
*/

// Assuming the host is little-endian:

uint16_t htons(uint16_t hostshort) {
    return (hostshort >> 8) | (hostshort << 8);
}

uint32_t htonl(uint32_t hostlong) {
    return ((hostlong >> 24) & 0xff) | // Move first byte to last
           ((hostlong << 8) & 0xff0000) | // Move third byte to second
           ((hostlong >> 8) & 0xff00) | // Move second byte to third
           ((hostlong << 24) & 0xff000000); // Move last byte to first
}

// To test the functions:
#include <stdio.h>

int main() {
    uint16_t val16 = 0x1234;
    uint32_t val32 = 0x12345678;

    printf("Original 16-bit value: 0x%x\n", val16);
    printf("Network ordered 16-bit value: 0x%x\n", htons(val16));
    printf("Original 32-bit value: 0x%x\n", val32);
    printf("Network ordered 32-bit value: 0x%x\n", htonl(val32));

    return 0;
}
