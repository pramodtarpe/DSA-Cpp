#include <bits/stdc++.h>
#include "binarytree.h"
#include "LinkedList.h"

#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
Node* create_LL(BinaryTreeNode* root){
  if(root == NULL){
    return NULL;
  }
  Node* rootLL = new Node(root->data);
  Node* leftLL = create_LL(root->left);
  Node* rightLL = create_LL(root->right);
  if(leftLL != NULL){
    Node* temp = leftLL;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = rootLL;
  }
  rootLL->next = rightLL;
  if(leftLL == NULL) return rootLL;
  return leftLL;
}

int main(){
  FASTIO
  int arr[]{1,2,3,4,5,6,7};
  BinaryTreeNode* root = create_from_array(arr,0,6);
  cout<<endl;
  print_bt(root);
  cout<<boolalpha;
  cout<<"BST 1: "<<isBST(root)<<endl;
  cout<<"BST 2: "<<is_bst(root)<<endl;
  cout<<"---------------------------------------------------------------------"<<endl;

  display(create_LL(root));

  return 0;
}
