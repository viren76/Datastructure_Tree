// *****Introduction to Trees******
// A tree is a collection of nodes connected to each other by means of “edges” which are either directed or undirected. 
// One of the nodes is designated as “Root node” and the remaining nodes are called child nodes or the leaf nodes of the root node. 
// In general, each node can have as many children but only one parent node.

//*******Time Complexity*******
// For searching element 1, we have to traverse all elements (in order 3, 2, 1). Therefore, searching in binary search tree has worst case complexity of O(n). 
// In general, time complexity is O(h) where h is height of BST.

//Insertion in trees
#include <bits/stdc++.h>
using namespace std;
class TreeNode{
   public:
      int val;
      TreeNode *left, *right;
      TreeNode(int data){
         val = data;
         left = right = NULL;
      }
};
void insert(TreeNode **root, int val){
   queue<TreeNode*> q;
   q.push(*root);
   while(q.size()){
      TreeNode *temp = q.front();
      q.pop();
      if(!temp->left){
         if(val != NULL)
            temp->left = new TreeNode(val);
         else
            temp->left = new TreeNode(0);
         return;
      }
      else{
         q.push(temp->left);
      }
      if(!temp->right){
         if(val != NULL)
            temp->right = new TreeNode(val);
         else
            temp->right = new TreeNode(0);
         return;
      }
      else{
         q.push(temp->right);
      }
   }
}
TreeNode *make_tree(vector<int> v){
   TreeNode *root = new TreeNode(v[0]);
   for(int i = 1; i<v.size(); i++){
      insert(&root, v[i]);
   }
   return root;
}
void tree_level_trav(TreeNode*root){
   if (root == NULL) return;
      cout << "[";
   queue<TreeNode *> q;
   TreeNode *curr;
   q.push(root);
   q.push(NULL);
   while (q.size() > 1) {
      curr = q.front();
      q.pop();
      if (curr == NULL){
         q.push(NULL);
      }
      else {
         if(curr->left)
            q.push(curr->left);
         if(curr->right)
            q.push(curr->right);
         if(curr->val == 0 || curr == NULL){
            cout << "null" << ", ";
         }
         else{
            cout << curr->val << ", ";
         }
      }
   }
   cout << "]"<<endl;
}
class Solution {
public:
   TreeNode* insertIntoBST(TreeNode* root, int val) {
      if(!root)return new TreeNode(val);
      if(root->val > val){
         root->left = insertIntoBST(root->left, val);
      }
      else root->right = insertIntoBST(root->right, val);
         return root;
   }
};
main(){
   Solution ob;
   vector<int> v = {4,2,7,1,3};
   TreeNode *root = make_tree(v);
   tree_level_trav(ob.insertIntoBST(root, 5));
}

//Explanation of code
// 1. This method is recursive. this is called insert(), this takes a value v.
// 2. if root is null, then create a node with given value v and make that as root
// 3. if value of root > v, then
// 4. left of root := insert(left of the root, v)
// 5 else right of the root := insert(right of the root, v)
// 6. return root