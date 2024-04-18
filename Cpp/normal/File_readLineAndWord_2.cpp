#include <iostream>
#include <fstream>
#include <string>

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
        size_t pos = 0;
        while ((pos = line.find_first_not_of(" \t\n", pos)) != string::npos) { // space, tab, new line
            ++wordCount;
            pos = line.find_first_of(" \t\n", pos);
        }
    }

    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;

    file.close();

    return 0;
}
