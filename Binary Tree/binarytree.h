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
vector<int>* path_bt(BinaryTreeNode* root, int n){
  if(root == NULL) return NULL;

  if(root->data == n){
    vector<int>* output = new vector<int>();
    output->push_back(root->data);
    return output;
  }
  vector<int>* leftout = path_bt(root->left, n);
  if (leftout != NULL){
    leftout->push_back(root->data);
    return leftout;
  }
  vector<int>* rightout = path_bt(root->right, n);
  if (rightout != NULL){
    rightout->push_back(root->data);
    return rightout;
  }
  else return NULL;
}

void inOrder(BinaryTreeNode* root){
  //Left Root right
  if(root==NULL){
    return ;
  }
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void preOrder(BinaryTreeNode* root){
  //Root left right
  if(root == NULL){
    return ;
  }
  cout<< root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(BinaryTreeNode* root){
  //left Right Root
  if(root == NULL){
    return ;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<< " ";
}

int treeHeight(BinaryTreeNode* root){
  if(root == NULL) return 0;
  int height = 0;
  return 1 + (max(treeHeight(root->left), treeHeight(root->right)));
}

int treeDiameter_old(BinaryTreeNode* root){
  if(root == NULL) return 0;
  int o1 = treeHeight(root->left) + treeHeight(root->right) + 1;
  int o2 = treeDiameter_old(root->left);
  int o3 = treeDiameter_old(root->right);
  return max( o1, max(o2,o3) );
}

pair<int,int> treeDiameter_new(BinaryTreeNode* root){
  pair<int,int> p;
  if(root == NULL){
    p.first = 0;
    p.second = 0;
    return p;
  }
  pair<int,int> left = treeDiameter_new(root->left);
  pair<int,int> right= treeDiameter_new(root->right);
  int ld = left.second;
  int rd = right.second;
  int lh = left.first;
  int rh = right.first;
  int height = 1 + max(lh, rh);
  int diameter = max(lh+rh, max(ld,rd));
  p.first = height;
  p.second = diameter;
  return p;
}

int diameterOpt(BinaryTreeNode* root, int* height = new int{0}){
  int lh = 0;
  int rh = 0;
  int ld = 0;
  int rd = 0;
  if(root == NULL){
    *height = 0;
    return 0;
  }
  ld = diameterOpt(root->left, &lh);
  rd = diameterOpt(root->right, &rh);

  *height = max(lh,rh) + 1;

  return max(lh+rh+1, max(ld,rd));
}
