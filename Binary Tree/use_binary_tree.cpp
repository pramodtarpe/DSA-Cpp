#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;

int main(){
  BinaryTreeNode* root = input_bt();
  cout<<endl;
  inOrder(root);
  cout<<endl;
  cout<<"-------------------------------------------------"<<endl;
  preOrder(root);
  cout<<endl;
  cout<<"-------------------------------------------------"<<endl;
  postOrder(root);
  cout<<endl;
  cout<<"-------------------------------------------------"<<endl;
  cout<<treeHeight(root)<<endl;
  cout<<"-------------------------------------------------"<<endl;
  cout<<"old : " <<treeDiameter_old(root)<<endl;
  cout<<"-------------------------------------------------"<<endl;
  cout<<"New: " <<(treeDiameter_new(root)).second + 1<<endl;
  cout<<"-------------------------------------------------"<<endl;
  cout<<"Opt: " <<diameterOpt(root)<<endl;
  return 0;
}
