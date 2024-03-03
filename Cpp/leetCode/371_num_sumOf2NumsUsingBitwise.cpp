#include <iostream>
#include <type_traits>
using namespace std;
/*
Given two integers a and b, return the sum of the two integers without using the
operators + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
*/

/*
Sum of two bits can be obtained by performing XOR (^) of the two bits. Carry bit
can be obtained by performing AND (&) of two bits.

Above is simple Half Adder logic that can be used to add 2 single bits. We can
extend this logic for integers. If x and y don’t have set bits at same
position(s), then bitwise XOR (^) of x and y gives the sum of x and y. To
incorporate common set bits also, bitwise AND (&) is used. Bitwise AND of x and
y gives all carry bits. We calculate (x & y) << 1 and add it to x ^ y to get the
required result.

eg = 5+2
5=> 0101
2=> 0010
keep = 0000
res = 0111 =>7

eg = 1010 => 10
   = 1111 => 15

keep= 10100
res =  0101

keep = 101000
res =   10001

keep = 000000
res =  111001
*/

int sum_rec(int x, int y) {
  int cary = (x & y) << 1;
  int res = x ^ y;
  if (cary == 0)
    return res;

  return sum_rec(cary, res);
}

int sum_itr(int a, int b) {
  while (b != 0) {
    int temp = (a & b) << 1;
    a = a ^ b;
    b = temp;
  }
  return a;
}

int sum_itr_1(int a, int b) {
  while (b != 0) {
    int Xor = (a ^ b);
    int And = a & b;
    int Carry = And << 1;
    
    a = Xor;
    b = Carry;
  }
  return a;
}

int main() {
  cout << "sum_rec:" << sum_rec(12, 15) << endl;
  cout << "sum_itr:" << sum_itr(12, 15) << endl;
  cout << "sum_itr:" << sum_itr_1(12, 15) << endl;
  return 0;
}