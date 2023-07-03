#include <algorithm>
#include <iostream>
#include <queue>
#include <type_traits>
#include <vector>

/*
103. Binary Tree Zigzag Level Order Traversal
Medium
Given the root of a binary tree, return the zigzag level order traversal of its
nodes' values. (i.e., from left to right, then right to left for the next level
and alternate between).



Example 1:
          3
        9   20
           15   7


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
*/

/*
Approch: will use queue

for each level wil prepare the vector from queue and make it empty
but for the next level element also will push while preparing the vector for
each level

 Loop(queue is not empty)
   empty queue make level_vector
   fill queue for next level
 each time need to reverse the queue
return List[level_vector]


*/
using namespace std;
struct node {
  int data;
  struct node *left{nullptr};
  struct node *right{nullptr};
  node(int data) : data(data) {}
};

typedef struct node *NODE;

void inorder(struct node *root) {
  if (!root)
    return;
  inorder(root->left);
  cout << root->data << ",";
  inorder(root->right);
}

vector<vector<int>> levelOrder(NODE root) {
  if (!root) {
    {}; // empty initializer list
  }
  vector<vector<int>> result;
  deque<NODE> myQueue; // deque of NODE not the value
  // first node needs to be pushed before intering into loop
  myQueue.push_front(root);
  bool reverse = true; // This needs to be toggle
  while (!myQueue.empty()) {
    vector<int> level_vec;
    deque<NODE> myRevQue;       // this is for reverse queue
    int q_cnt = myQueue.size(); // current level queue size

    for (int i = 0; i < q_cnt; i++) {
      auto node = myQueue.front(); // 1.prepare level_vector
      level_vec.push_back(node->data);
      myQueue.pop_front();

      if (reverse) {
        if (node->left) // 2.prepare queue for the next level elements
          myRevQue.push_front(node->left);
        if (node->right)
          myRevQue.push_front(node->right);
      } else {
        if (node->right)
          myRevQue.push_front(node->right);
        if (node->left)
          myRevQue.push_front(node->left);
      }
    }

    myQueue.insert(myQueue.begin(), myRevQue.begin(), myRevQue.end());
    result.push_back(level_vec); // 3.push each level_vector into result list
    reverse = !reverse;
  }
  return result;
}

int main(void) {
  /*
                   1
              2       3
            4   5   6    7
          10               30
        20
  */
  // level traversal: 1,2,3,4,5,6,7,10,20
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  root->right->right->right = new node(30);
  root->left->left->left = new node(10);
  root->left->left->left->left = new node(20);

  // op=> 1,2,3,4,5,6,7,10,30,20,

  cout << "levelOrder:";
  vector<vector<int>> res = levelOrder(root);
  for (auto lv : res)
    for (int x : lv)
      cout << x << ",";
  return 0;
}