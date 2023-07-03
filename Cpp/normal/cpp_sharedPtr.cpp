#include <cstddef>
#include <iostream>
// more than one pointer to same object
// reference counting model is used
using namespace std;
template <typename T> class SharedPtr {
  class counter {
    int ct{0};

  public:
    counter() = default;
    int getCt() { return ct; }
    void operator++() { ct++; }
    void operator++(int) { ct++; }
    void operator--() { ct--; }
    void operator--(int) { ct--; }
  };

private:
  T *ptr;
  counter *cnt;

public:
  // Constuctor
  explicit SharedPtr(T *ptr = nullptr) : ptr(ptr) {
    cnt = new counter();
    if (ptr) {
      (*cnt)++;
    }
  }

  // copy constructor
  SharedPtr(const SharedPtr<T> &sh_ptr) {
    std::cout << "copy called" << std::endl;
    this->ptr = sh_ptr.ptr;
    cnt = sh_ptr.cnt;
    (*cnt)++;
  }
  // move constructor
  SharedPtr(SharedPtr<T> &&sh_ptr) {
    std::cout << "move called" << std::endl;
    if (this->ptr != sh_ptr.ptr) {
      this->ptr = sh_ptr.ptr;
      cnt = sh_ptr.cnt;
      sh_ptr.ptr = nullptr;
      sh_ptr.cnt = 0;
    }
  }

  // destructor
  ~SharedPtr() {
    (*cnt)--;
    if (cnt->getCt() == 0) {
      delete cnt;
      delete ptr;
    }
  }

  int getRefCnt() { return cnt->getCt(); }
  T *getPtr() { return ptr; }
  T *operator->() { return ptr; }
  T &operator*() { return *ptr; }
};

int main() {
  SharedPtr<int> shptr1(new int(5));
  cout << "shptr1 = " << shptr1.getPtr() << ",ref cnt = " << shptr1.getRefCnt()
       << endl;

  SharedPtr<int> shptr2(move(shptr1));
  cout << "shptr2 = " << shptr2.getPtr() << ",ref cnt = " << shptr2.getRefCnt()
       << endl;
  if (!shptr1.getPtr()) {
    cout << "shptr1 is null " << endl;
  }

  SharedPtr<int> shptr3(shptr2);
  cout << "shptr3 = " << shptr3.getPtr() << ",ref cnt = " << shptr3.getRefCnt()
       << ",value = " << *shptr3 << endl;
  cout << "shptr2 = " << shptr3.getPtr() << ",ref cnt = " << shptr2.getRefCnt()
       << endl;

  return 0;
}