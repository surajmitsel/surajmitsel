#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void reverseArray(int array[], int start, int end) {
  while (start < end) {
    swap(&array[start], &array[end]);
    start++;
    end--;
  }
}

void reverseArray_rec(int array[], int start, int end) {
  if (start >= end)
    return;
  swap(&array[start], &array[end]);
  reverseArray_rec(array, start + 1, end - 1);
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6};

  int numelem = sizeof(array) / sizeof(array[0]);
  reverseArray(array, 0, numelem - 1);
  reverseArray_rec(array, 0, numelem - 1);

  for (int i = 0; i < numelem; i++) {
    cout << "array: " << array[i] << endl;
  }
  return 0;
}