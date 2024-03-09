#include <iostream>
#include <set>
using namespace std;

class PriorityQueue {
private:
    set<int> pq;

public:
    // Function to insert an element into the priority queue
    void insert(int val) {
        pq.insert(val);
    }

    // Function to remove the maximum priority element from the queue
    int removeMax() {
        if (isEmpty()) {
            cout << "Priority Queue is empty" << endl;
            return -1; // Or throw an exception
        }

        int maxVal = *pq.rbegin(); // Get the maximum element
        pq.erase(--pq.end()); // Remove the maximum element
        return maxVal;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return pq.empty();
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(20);
    pq.insert(15);
    pq.insert(30);

    cout << "Max priority element: " << pq.removeMax() << endl; // 30
    cout << "Max priority element: " << pq.removeMax() << endl; // 20

    return 0;
}
