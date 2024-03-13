#include <iostream>
#include <queue>
#include <stack>

using namespace std;
void printQueue(queue<int> &que) {
  if (que.empty()) {
    cout << "empty queue";
    return;
  }
  while (!que.empty()) {
    int data = que.front();
    cout << "data: " << data << endl;
    que.pop(); //remove element from queue
  }
}
void reverse(queue<int> &que) {
  int size = que.size();
  for (int i = 0; i < size; i++) {
  }
}
void reverseQueue(queue<int> &que) {
  if (que.empty()) {
    cout << "empty queue";
    return;
  }
  stack<int> stk;
  while (!que.empty()) {
    stk.push(que.front());
    que.pop();
  }
  while (!stk.empty()) {
    que.push(stk.top());
    stk.pop();
  }
}
int main() {
  queue<int> qu;
  qu.push(5);
  qu.push(4);
  qu.push(3);
  qu.push(2);
  qu.push(1);

  reverseQueue(qu);
  printQueue(qu);

  return 0;
}
