#include <bits/stdc++.h>
#include "Trees.h"
using namespace std;


int main(){
  // TreeNode* root = new TreeNode(1);
  // TreeNode* node1 = new TreeNode(2);
  // TreeNode* node2 = new TreeNode(3);
  //
  // root->children.push_back(node1);
  // root->children.push_back(node2);
  TreeNode* root = input_tree();
  printTree(root);
  // printTree(root);
  cout<<endl;
  cout<<"size: "<<treeSize(root)<<endl;
  cout<<"height: "<<treeHeight(root)<<endl;
  cout<<endl;
  cout<<"Leaves: "<<totalLeaf(root)<<endl;

  return 0;
}
