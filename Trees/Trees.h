#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
  int data;
  vector<TreeNode*> children;
public:
  TreeNode(int data){
    this->data = data;
  }
  ~TreeNode(){
    for(int i=0;i<children.size();i++){
      delete children[i];
    }
  }
};


void print(TreeNode* root){
    cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++)
      cout<<root->children[i]->data<<" ";
      cout<<endl;
    for(int i=0;i<root->children.size();i++){
      print(root->children[i]);
    }
}
TreeNode* input_tree(){
  cout<<"Enter root: ";
  int data;
  cin>>data;
  TreeNode* root = new TreeNode(data);
  queue<TreeNode*> pending;
  pending.push(root);
  while(pending.size()!=0){
    TreeNode* front = pending.front();
    pending.pop();
    int child;
    cout<<"Enter No. of children "<<front->data<<": ";
    cin>>child;
    for(int i=0;i<child;i++){
      cout<<"Enter child "<<i+1<<" data: ";
      cin>>data;
      TreeNode* child = new TreeNode(data);
      front->children.push_back(child);
      pending.push(child);
    }
  }
  return root;
}
void printTree(TreeNode* root){
  queue<TreeNode*> pending;
  pending.push(root);
  while(!pending.empty()){
    TreeNode* current = pending.front();
    cout<<current->data<<": ";
    for(int i=0;i<current->children.size();i++){
      cout<<current->children[i]->data<<" ";
    }
    cout<<endl;
    pending.pop();
    for(int i=0;i<current->children.size();i++){
      pending.push(current->children[i]);
    }
  }
}

int treeSize(TreeNode* root){
  int size = 1;
  for(int i=0;i<root->children.size();i++){
    size += treeSize(root->children[i]);
  }
  return size;
}

int treeHeight(TreeNode* root){
  int height = 0;
  for(int i=0;i<root->children.size();i++){
    height = max(height,treeHeight(root->children[i]));
  }
  return 1 + height;
}

void print_depth(TreeNode* root, int d){
  if(d==0){
    cout<<root->data<<" ";
  }
  for(int i=0;i<root->children.size();i++){
    print_depth(root->children[i],d-1);
  }
}

int totalLeaf(TreeNode* root){
  int count=0;
  if(root->children.empty()){
    return 1;
  }
  for(int i=0;i<root->children.size();i++){
    count += totalLeaf(root->children[i]);
  }
  return count;
}
