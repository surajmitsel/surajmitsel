#include <stack>
#include <climits>
#include <iostream>
/*
155. Min Stack
Medium

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 
Constraints:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

class MinStack {
private:
    std::stack<int> dataStack;
    std::stack<int> minStack;

public:
    /** initialize your data structure here. */
    MinStack() {
        minStack.push(INT_MAX); // Initialize with INT_MAX to handle empty stack case
    }

    void push(int val) {
        dataStack.push(val);
        minStack.push(std::min(val, minStack.top())); // Update minStack with minimum value so far
    }

    void pop() {
        dataStack.pop();
        minStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    // Create a MinStack object
    MinStack minStack;

    // Push elements onto the stack
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    // Print the minimum element in the stack
    std::cout << "Minimum element in the stack: " << minStack.getMin() << std::endl;

    // Pop an element from the stack
    minStack.pop();

    // Print the top element in the stack
    std::cout << "Top element in the stack: " << minStack.top() << std::endl;

    // Print the minimum element in the stack
    std::cout << "Minimum element in the stack: " << minStack.getMin() << std::endl;

    return 0;
}