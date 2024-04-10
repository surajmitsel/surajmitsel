#include <iostream>
using namespace std;

class PrePost {
private:
  int data;

public:
  PrePost(int data) : data(data) {}
  int getdata() { return data; }

  PrePost& operator++() // Pre increment
  {
    this->data++;
    return *this;
  }

  PrePost& operator++(int) // Post increment
  {
    static PrePost old(*this); // Copy old in static obj
    this->data++;
    return old;
  }
};

int main() {
  PrePost temp(4);
  int x = (++temp).getdata();
  int y = temp.getdata();

  cout << "PreIncrement:  data x = " << x << ",data y = " << y << endl;

  PrePost temp1(4);
  x = (temp1++).getdata();
  y = temp.getdata();

  cout << "PostIncrement:  data x = " << x << ",data y = " << y << endl;

  return 0;
}