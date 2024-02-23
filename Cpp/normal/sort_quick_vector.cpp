#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            if(i!=j) std::swap(arr[i], arr[j]);
            cout << "i:" << i << ", j:" << j << endl; 
        }
        
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print the elements of the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original array: ";
    printArray(arr);

    // Perform QuickSort
    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}