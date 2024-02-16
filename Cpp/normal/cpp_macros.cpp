#include <iostream>
#include <string>
using namespace std;

// bit pos start with 0 and max is variable data type
// num should be an variable not the an constant
#define CLEAR_BIT(num, pos) (num = (num & ~(1 << pos)))

#define SET_BIT(num, pos) (num = (num | (1 << pos)))

#define TOGGLE_BIT(num, pos) (num = (num ^ (1 << pos)))

#define SWAP(a, b) ((a ^= b ^= a ^= b))

#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)

#define LIMIT(x, min, max) ((x > max) ? max : (x < min) ? min : x)

#define SIZE_OF(value) ((char *)(&value + 1) - (char *)(&value))

#define POW_2(value) (1 << value)

#define IS_POW_2(num) ((num & (num - 1) ? false : true))

#define NUM_ARRAY_ELM(arr) (sizeof(arr) / sizeof(arr[0]))

#define NIBBLE_SWAP(value) (((value & 0x0F) << 4) | ((value & 0xF0) >> 4))

#define SET_N_BITS(value, numBits, pos)                                        \
  (value = (value | ((1 << numBits) - 1) << pos))

#define CLEAR_N_BITS(value, numBits, pos)                                      \
  (value = (value & (~((1 << numBits) - 1) << pos)))
int main() {

  // CLEAR_BIT
  std::cout << "macro: clear bit" << endl;
  int val_clr = 0x1452; // 0001 0100 0101 0010
  cout << "before:0x" << std::hex << val_clr << endl;
  CLEAR_BIT(val_clr, 4);
  cout << "after:0x" << std::hex << val_clr << endl; //0x1442

  // SET_BIT
  cout << endl << endl;
  std::cout << "macro: set bit" << endl;
  int val_set = 0x1452; // 0001 0100 0101 0010
  cout << "before:0x" << std::hex << val_set << endl;
  SET_BIT(val_set, 15);
  cout << "after:0x" << std::hex << val_set << endl; //0x9452

  // TOGGLE_BIT
  cout << endl << endl;
  std::cout << "macro: toggle bit" << endl;
  int val_tog = 0x1452; // 0001 0100 0101 0010
  cout << "before:0x" << std::hex << val_tog << endl;
  TOGGLE_BIT(val_tog, 0);
  cout << "after:0x" << std::hex << val_tog << endl; // 0x1453
  TOGGLE_BIT(val_tog, 4);
  cout << "after:0x" << std::hex << val_tog << endl; // 0x1443

  // SWAP values
  cout << endl << endl;
  std::cout << "macro: SWAP values" << endl;
  int value_a = -125;
  int value_b = 759;
  cout << "before a:" << std::dec << value_a << ",b:" << value_b << endl;
  SWAP(value_a, value_b);
  cout << "before a:" << std::dec << value_a << ",b:" << value_b << endl;

  // MIN values
  cout << endl << endl;
  std::cout << "min value" << endl;
  int value_min = 100;
  cout << "before:" << std::dec << value_min << endl;
  value_min = MIN(value_min, 20);
  cout << "after:" << std::dec << value_min << endl;
  value_min = 10;
  value_min = MIN(value_min, 20);
  cout << "after:" << std::dec << value_min << endl;

  // MAX values
  cout << endl << endl;
  std::cout << "max value" << endl;
  int value_max = 100;
  cout << "before:" << std::dec << value_max << endl;
  value_max = MAX(value_max, 20);
  cout << "after:" << std::dec << value_max << endl;
  value_max = 10;
  value_max = MAX(value_max, 20);
  cout << "after:" << std::dec << value_max << endl;

  // POW_2 values
  cout << endl << endl;
  std::cout << "POW_2" << endl;
  int val_pow = 6;
  cout << "before:" << std::dec << val_pow << endl;
  val_pow = POW_2(val_pow);
  cout << "after:" << std::dec << val_pow << endl;

  // SET_N_BITS
  cout << endl << endl;
  std::cout << "macro: SET_N_BITS" << endl;
  int val_set_n = 0x00;
  cout << "before:0x" << std::hex << val_set_n << endl;
  SET_N_BITS(val_set_n, 3, 0);
  cout << "after:0x" << std::hex << val_set_n << endl;

  // CLEAR_N_BITS
  cout << endl << endl;
  std::cout << "macro: CLEAR_N_BITS" << endl;
  int clr_set_n = 0xFF;
  cout << "before:0x" << std::hex << clr_set_n << endl;
  CLEAR_N_BITS(clr_set_n, 3, 0);
  cout << "after:0x" << std::hex << clr_set_n << endl;

  // NUM_ARRAY_ELM
  cout << endl << endl;
  int arr[7] = {1, 2, 3, 4, 5};
  std::cout << "macro: NUM_ARRAY_ELM " << endl;
  int num_arr = NUM_ARRAY_ELM(arr);
  cout << "num_arr:" << std::dec << num_arr << endl;

  // SIZE_OF
  cout << endl << endl;
  struct test {
    char a;
    char b;
    int c;
  };
  test obj;
  std::cout << "macro: SIZE_OF " << endl;
  int size_ = SIZE_OF(obj);
  cout << "size:" << std::dec << size_ << endl;

  // IS_POW_2
  std::cout << "macro: IS_POW_2: " << IS_POW_2(64) << endl;
  std::cout << "macro: IS_POW_2: " << IS_POW_2(59) << endl;
}
