#include <iostream>
#include <stack>

class Queue {
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

public:
    void enqueue(int value) {
        inputStack.push(value);
    }

    int dequeue() {
        if (outputStack.empty()) {
            // Transfer elements from inputStack to outputStack
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        if (outputStack.empty()) {
            std::cerr << "Queue is empty, cannot dequeue\n";
            return -1; // Or throw an exception
        }

        int frontValue = outputStack.top();
        outputStack.pop();
        return frontValue;
    }

    bool isEmpty() const {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " "; // Output: 1 2 3
    }
    std::cout << std::endl;

    return 0;
}
