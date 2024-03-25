#include <algorithm>
#include <iostream>
using namespace std;

// METHOD1: recursive
int binarySearchIndex_rec(int array[], int low, int high, int value) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    if (array[mid] == value)
      return mid;
    else if (value < array[mid])
      return binarySearchIndex_rec(array, low, mid - 1, value);
    else
      return binarySearchIndex_rec(array, mid + 1, high, value);
  }
  return -1;
}

// METHOD2: interative
int binarySearchIndex_itr(int array[], int low, int high, int value) {
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (array[mid] == value)
      return mid;
    else if (value < array[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int main() {
  // int array[] = {2, 5, 12, 16, 23, 38, 56, 72, 91};
  int array[] = {1, 2, 5, 8, 9, 10, 13, 18, 19, 20};
  int numelem = sizeof(array) / sizeof(array[0]);
  int find = 13;
  cout << "rec_search index:" << binarySearchIndex_rec(array, 0, numelem, find)
       << endl;
  cout << "itr_search index:" << binarySearchIndex_itr(array, 0, numelem, find)
       << endl;
  return 0;
}