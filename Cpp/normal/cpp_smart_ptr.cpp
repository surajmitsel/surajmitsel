#include <iostream>

using namespace std;
template <typename T> class SmartPtr {
  T *ptr;

public:
  // Constructor
  explicit SmartPtr(T *ptr = nullptr) : ptr(ptr) {
    cout << "Constructor" << endl;
  }

  // destructor
  ~SmartPtr() {
    delete ptr;
    cout << "destructor" << endl;
  }

  T &operator*() { return *ptr; }
  T *operator->() { return ptr; }
};

int main() {
  SmartPtr<int> ptr(new int(5));
  cout << "value:" << *ptr << endl;
  return 0;
}