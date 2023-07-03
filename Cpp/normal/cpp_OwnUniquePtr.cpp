#include <iostream>
using namespace std;
// only one pointee to the object is allowed
// copy of the pointer is not allowed
// only pointer can move from one to other
template <typename T> class UniquePtr {
private:
  T *ptr;

public:
  explicit UniquePtr(T *ptr = nullptr) : ptr(ptr) {
    cout << "constructor" << endl;
  }
  ~UniquePtr() { cout << "destructor" << endl; }

  T *getPtr() { return ptr; }

  T *operator->() { return ptr; }
  T &operator*() { return *ptr; }

  UniquePtr(UniquePtr<T> &&uptr) noexcept {
    cout << "move constructor" << endl;
    ptr = std::move(uptr.ptr);
    uptr.ptr = nullptr;
  }

  UniquePtr<T> &operator=(UniquePtr<T> &&uptr) noexcept {
    cout << "Assignment move Operator" << std::endl;
    if (this == &uptr)
      return *this;
    ptr = std::move(uptr.ptr);
    uptr.ptr = nullptr;
    return *this;
  }

  UniquePtr(const UniquePtr<T> &ptr) = delete; // delete copy

  UniquePtr<T> &
  operator=(const UniquePtr<T> &&ptr) = delete; // delete assignment
};
int main() {
  UniquePtr<int> ptr1(new int(10));
  cout << "value = " << *ptr1 << endl;
  cout << "ptr1 = " << ptr1.getPtr() << endl;

  UniquePtr<int> ptr2;
  ptr2 = std::move(ptr1); // Assignment move Operator

  cout << "ptr1 = " << ptr1.getPtr() << endl;
  cout << "ptr2 = " << ptr2.getPtr() << endl;

  UniquePtr<int> ptr3(std::move(ptr2)); // move constructor

  cout << "ptr1 = " << ptr1.getPtr() << ",value = " << *ptr1 << endl;
  cout << "ptr2 = " << ptr2.getPtr() << endl;
  cout << "ptr3 = " << ptr3.getPtr() << endl;

  return 0;
}