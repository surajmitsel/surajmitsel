#include <iostream>
using namespace std;

template <typename T, int size> 
class Queue {
  T *data{nullptr};
  T *array{nullptr};
  int length{0};
  int front{0};
  int rear{-1};
  int cnt{0};

public:
  Queue() {
    length = size;
    array = new T[size];
  }
  ~Queue() { delete[] array; }
  bool IsEmpty() { return (cnt == 0); }
  bool IsFull() { return (cnt >= length); }
  int count() { return cnt; }

  void dequeue(void) // only remove the element
  {
    if (IsEmpty()) {
      cout << "Queue underflow!";
      return;
    }
    cout << "removing: " << array[front] << endl;
    front = (front + 1) % length;
    cnt--;
  }

  void enqueue(T data) {
    if (IsFull()) {
      cout << "Queue overflow!" << endl;
      return;
    }
    cout << "Inserting Item: " << data << endl;
    rear = (rear + 1) % length;
    array[rear] = data;
    cnt++;
  }

  T Front() {
    if (IsEmpty()) {
      cout << "Queue underflow!" << endl;
      return -1;
    }
    return array[front];
  }
};

int main() {
  Queue<int, 5> my_queue;

  cout << "Queue is Empty = " << my_queue.IsEmpty() << endl;
  my_queue.enqueue(1);
  my_queue.enqueue(2);
  my_queue.enqueue(3);
  my_queue.enqueue(4);
  my_queue.enqueue(5);
  my_queue.enqueue(6);

  cout << "queue count:" << my_queue.count() << endl;

  my_queue.dequeue();
  my_queue.dequeue();
  cout << "queue count:" << my_queue.count() << endl;
  my_queue.dequeue();
  my_queue.dequeue();
  my_queue.dequeue();
  my_queue.dequeue();

  return 0;
}