#include <iostream>
#include <set>
using namespace std;
// using binary seach tree we can do this
// during insert we if repeated element
// found we can remove it

// METHOD1
struct node {
  int data;
  struct node *left{nullptr}, *right{nullptr};
  node(int data) : data(data) {}
};
struct node *bst_insert(struct node *root, int data) {
  if (!root)
    return new node(data);
  if (data < root->data)
    root->left = bst_insert(root->left, data);
  else if (data > root->data)
    root->right = bst_insert(root->right, data);
  else
    ; // ignore the data to insert
  return root;
}

void bst_print(struct node *root) {
  if (!root)
    return;
  bst_print(root->left);
  cout << "elem:" << root->data << ", " << endl;
  bst_print(root->right);
}

// METHOD2
int usingSet(int array[], int n) {
  set<int> mySet; // this is also an bst
  int j = 0;      // stores uniqe num elements

  // insert into set
  for (int i = 0; i < n; i++)
    mySet.insert(array[i]);

  // read from set
  for (auto val : mySet)
    array[j++] = val;

  return j;
}

// METHOD 3 
void removeDupFromVec(vector<int> &vec){
    set<int> myset; // bst no duplicate: O(logn) 

    for(auto& i : vec)
        myset.insert(i);  
    
    vec.clear();
    
    for(auto & i: myset)
         vec.push_back(i);
}
int main() {
  int array[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 1, 1, 2, 2};
  int numelem = sizeof(array) / sizeof(array[0]);
  struct node *root = nullptr;
  //----------------------
  cout << "usingBST" << endl;
  for (int i; i < numelem; i++) {
    root = bst_insert(root, array[i]);
  }
  bst_print(root);

  //----------------------
  cout << "usingSet" << endl;
  int cnt = usingSet(array, numelem);
  for (int i = 0; i < cnt; i++) {
    cout << array[i] << ",";
  }
  cout << endl;

  //----------------------
  cout << "removeDupFromVec" << endl;
  vector<int> vec{1,5,6,7,8,4,1,5,8,10,1,6};
  removeDupFromVec(vec);
  for (int &i:vec)
      cout << i << ",";
  cout << endl;

  return 0;
}
