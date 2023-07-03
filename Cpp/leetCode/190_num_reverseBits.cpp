#include <bitset>
#include <cstdint>
#include <iostream>
#include <type_traits>

using namespace std;
/*
190. Reverse Bits
Easy
Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In
this case, both input and output will be given as a signed integer type. They
should not affect your implementation, as the integer's internal binary
representation is the same, whether it is signed or unsigned. In Java, the
compiler represents the signed integers using 2's complement notation.
Therefore, in Example 2 above, the input represents the signed integer -3 and
the output represents the signed integer -1073741825.

Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents
the unsigned integer 43261596, so return 964176192 which its binary
representation is 00111001011110000010100101000000.

Example 2:
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents
the unsigned integer 4294967293, so return 3221225471 which its binary
representation is 10111111111111111111111111111111.
*/

uint32_t reverseBits_uint32(uint32_t val) {
  uint32_t result = 0;
  int pos = 0;
  while (val > 0) { // value is checked
    result = result + ((val % 2) << (31 - pos));
    val >>= 1;
    pos++;
  }
  return result;
}

int32_t reverseBits_int32(int32_t val) {
  int32_t result = 0;
  int pos = 0;
  while (pos < 32) { // pos is checked for all 32 bit
    result = result + ((val % 2) << (31 - pos));
    val >>= 1;
    pos++;
  }
  result = (val < 0) ? -result : result;
  return result;
}

int main() {
  int32_t value = -25;
  bitset<32> beforReverse(value);
  bitset<32> afterReverse(reverseBits_int32(value));
  cout << "Before reverseBits_int32:" << beforReverse << endl;
  cout << "after reverseBits_int32 :" << afterReverse << endl;

  uint32_t value1 = 4567;
  bitset<32> befor(value1);
  bitset<32> after(reverseBits_uint32(value1));
  cout << "Before reverseBits_uint32:" << befor << endl;
  cout << "after reverseBits_uint32 :" << after << endl;

  return 0;
}