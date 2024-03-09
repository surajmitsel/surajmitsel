#include <iostream>
using namespace std;
int removeDuplicate_1(int array[], int numelem) {
  if (numelem == 0 || numelem == 1) {
    return numelem;
  }
  int j = 0; // store index of next unique
  for (int i = 0; i < numelem - 1; i++) {
    if (array[i] != array[i + 1]) { // current != next then store
      array[j++] = array[i];
    }
  }
  // Store the last element as whether it is unique or
  // repeated, it hasn't stored previously
  array[j++]= array[numelem - 1];
  return j;
}

int removeDuplicate_2(int array[], int numelem) {
  if (numelem == 0 || numelem == 1) {
    return numelem;
  }
  int index = 0; // store index of next unique
  for (int i = 1; i < numelem; i++) {
    if (array[i] != array[index]) {  //current != prev then replace
      array[++index] = array[i];
    }
  }
  return index + 1;
}

int main() {
  int array[] = {10, 20, 20, 30, 40, 40, 40, 50};
  int numelem = sizeof(array) / sizeof(array[0]);
  //int numUnique = removeDuplicate_1(array, numelem);
  int numUnique = removeDuplicate_2(array,numelem);
  for (int i = 0; i < numUnique; i++) {
    cout << array[i] << ",";
  }
  return 0;
}