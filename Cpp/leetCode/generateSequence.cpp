#include <iostream>
#include <vector>

using namespace std;

void generateSequences(int n, vector<int>& sequence, vector<bool>& used) {
    if (sequence.size() == n) {
        // Base case: if the sequence has reached the desired length, print it
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        if (!used[i]) {
            // If the current number is not used, add it to the sequence
            sequence.push_back(i);
            used[i] = true;
            // Recursively generate the sequence
            generateSequences(n, sequence, used);
            // Backtrack: remove the last added number and mark it as unused
            sequence.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n = 3; // Length of the sequence
    vector<int> sequence;
    vector<bool> used(4, false); // Initialize a boolean array to keep track of used numbers

    generateSequences(n, sequence, used);

    return 0;
}
