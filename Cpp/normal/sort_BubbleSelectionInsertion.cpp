#include <iostream>
#include <type_traits>
using namespace std;

/*
light value comes up like the bubble
x=0, x < size-1
y=x, y < size-1-x
swap => [y] > [y+1]
*/
void bubble_sort(int array[], int size) {
  int x, y;
  for (int x = 0; x < size - 1; x++) {       // x=0, x < size-1
    for (int y = x; y < size - 1 - x; y++) { // y=x, y < size-1-x
      if (array[y] > array[y + 1]) {
        swap(array[y], array[y + 1]); // swap
      }
    }
  }
}

/*
search smallest number then replace the first position
then again from 2nd position search smalles num and replace to 2nd
x=0, x < size-1
  min_idx = x;
y=x+1, y < size
  min_idx > y then min_idx = y
swap => [min_idx] > [x]

*/
void selection_sort(int array[], int size) {
  int x, y, min_idx;
  for (int x = 0; x < size - 1; x++) { // x=0 , x < size-1
    min_idx = x;
    for (int y = x + 1; y < size; y++) { // y=x+1, y < size
      if (array[min_idx] > array[y]) {
        min_idx = y;
      }
    }
    swap(array[min_idx], array[x]);
  }
}

/*
short first 2 item
then short first 3 item
then short first 4 itme .. like a playing cards

// x=1, x < size
// key = [x]
// y = x-1
// y>=0 && [y] > key
//    [y + 1] = [y]
// [y + 1] = key
*/
void insertion_sort(int array[], int size) {
  int x, y, key;
  for (int x = 1; x < size; x++) { // x=1, x < size
    key = array[x];
    y = x - 1;
    // Move elements of arr[0..i-1],
    // that are greater than key, to one
    // position ahead of their
    // current position
    while (y >= 0 && array[y] > key) {
      array[y + 1] = array[y];
      y = y - 1;
    }
    array[y + 1] = key;
  }
}

int main() {
  int array_b[5] = {10, 50, 40, 20, 30};
  bubble_sort(array_b, 5);
  cout << "bubble_sort:";
  for (int i = 0; i < 5; i++) {
    cout << array_b[i] << ",";
  }

  cout << endl << endl;

  int array_s[5] = {10, 50, 40, 20, 30};
  selection_sort(array_s, 5);
  cout << "selection_sort:";
  for (int i = 0; i < 5; i++) {
    cout << array_s[i] << ",";
  }

  cout << endl << endl;

  int array_i[5] = {10, 50, 40, 20, 30};
  insertion_sort(array_i, 5);
  cout << "insertion_sort:";
  for (int i = 0; i < 5; i++) {
    cout << array_i[i] << ",";
  }

  return 0;
}