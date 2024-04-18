#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    getline(cin, filename);

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int wordCount = 0;
    int lineCount = 0;
    string line;

    while (getline(file, line)) {
        ++lineCount;

        // Count words in each line
        istringstream iss(line);
        string word;
        while (iss >> word) {
            ++wordCount;
        }
    }

    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;

    file.close();

    return 0;
}
