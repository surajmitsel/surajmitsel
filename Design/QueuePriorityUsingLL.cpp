#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    int priority;
    Node* next;

    // Constructor to initialize data, priority, and next pointer
    Node(int d, int p) : data(d), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* front; // Pointer to the front of the priority queue

public:
    // Constructor to initialize the priority queue
    PriorityQueue() : front(nullptr) {}

    // Function to insert an element into the priority queue
    void insert(int data, int priority) {
        Node* newNode = new Node(data, priority);
        if (front == nullptr || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to remove the maximum priority element from the queue
    int removeMax() {
        if (isEmpty()) {
            cerr << "Priority Queue is empty" << endl;
            return -1; // Or throw an exception
        }
        int maxElement = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return maxElement;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    PriorityQueue pq;

    // Insert elements with their priorities
    pq.insert(10, 2);
    pq.insert(20, 1);
    pq.insert(15, 3);
    pq.insert(30, 2);

    // Remove and print the maximum priority element
    while (!pq.isEmpty()) {
        cout << "Max priority element: " << pq.removeMax() << endl;
    }

    return 0;
}
