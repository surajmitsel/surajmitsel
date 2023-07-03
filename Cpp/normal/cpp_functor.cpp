// over loading () operator is creates the functors
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Fibonaci {
private:
  constexpr static int match = 10;
  constexpr static int inner_fac = 10;
  void fibc(int num) {
    int a = 0, b = 1, c = 0;
    while (c <= num) {
      c = a + b;
      a = b;
      b = c;
      cout << b << endl;
    }
  }

public:
  void operator()(int x) { fibc(x); }
  bool operator()(const int *x) { return *x == match; } // functor overloading
  int operator()(const string str, int factor) {
    if (str == "mul") {
      return factor * inner_fac;
    }
    return 0;
  }
};

int main() {
  // Fibonaci obj(10);//this is error its asking for constructor
  int data = 12;
  int array[] = {1, 2, 3, 4, 5};
  // auto fun = [](auto data) { return data; };
  Fibonaci obj;
  obj(data);

  cout << "matching = " << obj(const_cast<int *>(&data));
  std::transform(array, array + 5, array, obj("mul", 5));
  //   for (int i = 0; i < 5; i++)
  //     cout << "array = " << array[i] << endl;
  return 0;
}