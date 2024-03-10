#include <iostream>
#include <queue>

class Stack {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    void push(int value) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element into q1
        q1.push(value);

        // Move all elements back to q1 from q2
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        if (q1.empty()) {
            std::cerr << "Stack is empty, cannot pop\n";
            return -1; // Or throw an exception
        }

        int topValue = q1.front();
        q1.pop();
        return topValue;
    }

    bool isEmpty() const {
        return q1.empty();
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " "; // Output: 3 2 1
    }
    std::cout << std::endl;

    return 0;
}
