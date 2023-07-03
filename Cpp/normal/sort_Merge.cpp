#include <iostream>
#include <type_traits>
using namespace std;
/*
we devide the array in 2 partition
- sort the left array recursively
- sort the right array recursively
- merge the left and right array
*/
const int max = 10;
void merge_sort(int array[], int low, int mid, int high) {
  int l = low;
  int m = mid + 1;

  int index = low; // index of temp
  int result[10];  // creating shorted array

  while (l <= mid && m <= high) {
    if (array[l] <= array[m])
      result[index++] = array[l++]; // copy from left portion
    else
      result[index++] = array[m++]; // copy from right portion
  }

  if (l > mid) {
    int k = m;
    while (k <= high)
      result[index++] = array[k++];
  } else {
    int k = l;
    while (k <= mid) {
      result[index++] = array[k++];
    }
  }

  for (int i = low; i <= high; i++) {
    array[i] = result[i]; // copy result in actual array
  }
}
void partition(int array[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2; // mid index
    // make smallest partition
    partition(array, low, mid);
    partition(array, mid + 1, high);
    merge_sort(array, low, mid, high);
  }
}

int main() {
  int array_m[10] = {70, 50, 40, 40, 30, 60, 100, 90, 80, 10};
  int numElem = sizeof(array_m) / sizeof(array_m[0]);
  partition(array_m, 0, numElem - 1);
  cout << "merge_sort:";
  for (int i = 0; i < numElem; i++) {
    cout << array_m[i] << ",";
  }

  return 0;
}