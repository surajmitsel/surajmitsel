#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
using namespace std;

class PriorityQueue {
private:
    vector<int> pq;

public:
    // Function to insert an element into the priority queue
    void insert(int val) {
        pq.push_back(val);
        
        // Sort the vector after each insertion
        //1. sort(pq.begin(), pq.end(), greater<int>()); // this also can be used

        sort(pq.begin(), pq.end(), [](int a, int b) {
                                            return a > b; // Change to a < b for Increasing order
                                        });
    }

    // Function to remove the maximum priority element from the queue
    int removeMax() {
        if (isEmpty()) {
            cout << "Priority Queue is empty" << endl;
            return -1; // Or throw an exception
        }

        int maxVal = pq.front();
        pq.erase(pq.begin());
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

    cout << "Max priority element: " << pq.removeMax() << endl;
    cout << "Max priority element: " << pq.removeMax() << endl;

    return 0;
}
