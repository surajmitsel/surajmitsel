#include <array>
#include <iostream>

using namespace std;
template <typename T, int size> class Stack {
private:
  int top;
  int capacity;
  T *array;

public:
  Stack() {
    array = new T[size];
    top = -1;
    capacity = size;
  }

  ~Stack() {
    delete[] array;
    array = nullptr;
  }

  Stack(Stack &) = delete;        // delete copy
  T &operator=(Stack &) = delete; // delete assignment

  void push(T data) {
    if (isFull()) {
      cout << "Stack Overflow" << endl;
      return;
    }
    array[++top] = data;
  }

  T pop() {
    if (isEmpty()) {
      cout << "stack underflow!";
      return -1;
    }
    T data = array[top--];
    return data;
  }

  T Top() {
    if (isEmpty()) {
      cout << "stack underflow!";
      return;
    }
    T data = array[top];
    return data;
  }

  bool isFull() { return (top >= capacity - 1); }
  bool isEmpty() { return (top < 0); }
};

int main() {
  Stack<int, 6> my_stack;
  my_stack.push(1);
  my_stack.push(2);
  my_stack.push(3);
  my_stack.push(4);
  my_stack.push(5);
  my_stack.push(6);

  for (int i = 0; i <= 5; i++)
    cout << "data: " << my_stack.pop() << endl;

  return 0;
}