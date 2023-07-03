#include <iostream>
#include <memory> // for unique_ptr
using namespace std;

int main() {
  unique_ptr<int> ptr1(new int(5));

  cout << "value = " << *ptr1 << endl;

  // unique_ptr<int> ptr2 = ptr1; // This gives error
  unique_ptr<int> ptr2 = std::move(ptr1); // This works but makes ptr1 empty
  cout << "value = " << *ptr2 << endl;

  cout << "ptr1 = " << ptr1.get() << endl; // empty
  cout << "ptr2 = " << ptr2.get() << endl;

  shared_ptr<int> shptr1(new int(5));
  shared_ptr<int> shptr2 = shptr1;
  return 0;
}