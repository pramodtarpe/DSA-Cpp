#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode{
public:
  int data;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(int data){
    this->data = data;
    left = NULL;
    right = NULL;
  }
  ~BinaryTreeNode(){
    delete left;
    delete right;
  }
};

BinaryTreeNode* input_bt(){
  printf("Enter root: ");
  int data;
  std::cin>>data;
  BinaryTreeNode* root = new BinaryTreeNode(data);
  std::queue<BinaryTreeNode*> pending;
  pending.push(root);

  while(!pending.empty()){
    BinaryTreeNode* front = pending.front();
    pending.pop();
    int L,R;
    printf("Enter LR of %d: ",front->data);
    std::cin>>L>>R;
    if(L>0){
      BinaryTreeNode* Lchild = new BinaryTreeNode(L);
      front->left = Lchild;
      pending.push(Lchild);
    }

    if (R>0){
      BinaryTreeNode* Rchild = new BinaryTreeNode(R);
      front->right = Rchild;
      pending.push(Rchild);
    }
  }
  return root;
}

void print_bt(BinaryTreeNode* root){
  if(root == NULL) return;

  cout<<root->data<<": ";
  if(root->left != NULL){
    cout<<"L-"<<root->left->data<<" ";
  }
  if(root->right != NULL){
    cout<<"R-"<<root->right->data;
  }
  cout<<endl;
  print_bt(root->left);
  print_bt(root->right);
}

int maximum(BinaryTreeNode* root){
  if(root == NULL) return INT_MIN;
  return max(root->data, max(maximum(root->left),maximum(root->right)));
}
int minimum (BinaryTreeNode* root){
  if(root == NULL) return INT_MAX;
  return min(root->data,min(minimum(root->left),minimum(root->right)));
}

bool isBST(BinaryTreeNode* root){
  if(root == NULL){
    return true;
  }
  int leftmax = maximum(root->left);
  int rightmin = minimum(root->right);
  bool output =  (root->data > leftmax) &&  (root->data <= rightmin) && isBST(root->left) && isBST(root->right);
  return output;
}

bool is_bst(BinaryTreeNode* root, int lower = INT_MIN, int upper = INT_MAX){
  if(root == NULL){
    return true;
  }
  bool node = (root->data >= lower && root->data <= upper);
  if(!node) return false;
  return node && is_bst(root->left,lower,root->data-1) && is_bst(root->right,root->data,upper);
}

BinaryTreeNode* create_from_array(int arr[], int start,int end){
  if(start>end){
    return NULL;
  }

  int mid = (start+end)/ 2;
  BinaryTreeNode* root = new BinaryTreeNode(arr[mid]);
  root->left = create_from_array(arr, start, mid-1);
  root->right = create_from_array(arr, mid+1, end);

  return root;
}
