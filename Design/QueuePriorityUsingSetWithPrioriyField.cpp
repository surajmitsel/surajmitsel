#include <iostream>
#include <set>
using namespace std;

// Custom structure representing an element with priority
struct Element {
    int value;
    int priority;

    // Constructor
    Element(int v, int p) : value(v), priority(p) {}

    // Custom comparison operator
    bool operator<(const Element& other) const {
        // Elements are compared based on their priority
        // If priorities are equal, compare based on value
        if (priority == other.priority) {
            return value < other.value;
        }
        return priority < other.priority;
    }
};

class PriorityQueue {
private:
    set<Element> pq;

public:
    // Function to insert an element into the priority queue
    void insert(int value, int priority) {
        pq.emplace(value, priority);
    }

    // Function to remove the maximum priority element from the queue
    Element removeMax() {
        if (isEmpty()) {
            cerr << "Priority Queue is empty" << endl;
            return Element(-1, -1); // Or throw an exception
        }

        Element maxElement = *pq.rbegin();
        pq.erase(--pq.end());
        return maxElement;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const {
        return pq.empty();
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
        Element maxElement = pq.removeMax();
        cout << "Value: " << maxElement.value << ", Priority: " << maxElement.priority << endl;
    }

    return 0;
}
