#include <iostream>
#include <type_traits>
using namespace std;
/*
Similar to the Merge Sort algorithm, the Quick Sort algorithm is a Divide and
Conquer algorithm.

It initially selects an element as a pivot element and
partitions the given array around the picked pivot.

There are many different versions of quickSort that pick pivot in different
ways.
- Always pick the first element as a pivot (implemented below).
- Always pick the last element as the pivot.
- Pick a random element as a pivot.
- Pick median as a pivot.
*/
void print_array(int arr[]){
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << ",";
  }
}  

int partition(int array[], int low, int high) {
  cout << "partition:" << "low:" << low << ",high:" << high << ",pivot:" <<array[high]<<endl; 
  
  int pivot = array[high]; // actual pivot
  int i = low;             // index of smallest element

  // putting all the value to the left side of pivot
  for (int j = low; j < high; j++) {
    if (array[j] < pivot) {
      if (i != j)
        swap(array[i], array[j]);
      i++;
    }
  }
  swap(array[i], array[high]);
  return i;
}

void quick_sort(int array[], int low, int high) {
  if (low < high) {
    cout << "quick_sort:"; print_array(array);
    
    // get the partition index
    int pi = partition(array, low, high);

    // Sorting the left part
    quick_sort(array, low, pi - 1);

    // Sorting the right part
    quick_sort(array, pi + 1, high);
  }
}


int main() {
  int array_q[10] = {70, 50, 40, 40, 30, 60, 100, 90, 80, 10};
  int numElem = sizeof(array_q) / sizeof(array_q[0]);
  quick_sort(array_q, 0, numElem - 1);
  cout << "quick_sort:";
  for (int i = 0; i < numElem; i++) {
    cout << array_q[i] << ",";
  }

  return 0;
}