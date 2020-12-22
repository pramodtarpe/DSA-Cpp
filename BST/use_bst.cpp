#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int main(){
  cout<<boolalpha<<endl;
  BST tree;
  tree.insert(10);
  tree.insert(5);
  tree.insert(20);
  tree.insert(7);
  tree.insert(3);
  tree.insert(15);
  print_bt(tree.root);
  cout<<"--------------------------------------"<<endl;
  cout<<"--------------------------------------"<<endl;
  tree.erase(10);
  tree.erase(100);

  print_bt(tree.root);

  return 0;
}
