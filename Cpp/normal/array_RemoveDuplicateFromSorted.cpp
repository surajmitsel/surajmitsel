#include <iostream>
using namespace std;
int removeDuplicate(int array[], int numelem) {
  if (numelem == 0 || numelem == 1) {
    return numelem;
  }
  int j = 0; // store index of next unique
  for (int i = 0; i < numelem - 1; i++) {
    if (array[i] != array[i + 1]) {
      array[j++] = array[i];
    }
  }
  // Store the last element as whether it is unique or
  // repeated, it hasn't stored previously
  array[j++]= array[numelem - 1];
  return j;
}
int main() {
  int array[] = {10, 20, 20, 30, 40, 40, 40, 50};
  int numelem = sizeof(array) / sizeof(array[0]);
  int numUnique = removeDuplicate(array, numelem);
  for (int i = 0; i < numUnique; i++) {
    cout << array[i] << "," << endl;
  }
  return 0;
}