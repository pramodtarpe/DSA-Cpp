#include "binarytree.h"

class BST{
public:
  BinaryTreeNode* root;
  BST(){
    this->root = NULL;
  }
  // BST(BinaryTreeNode* node){
  //   this->root = node;
  // }
  // BST(int data){
  //   BinaryTreeNode* node = new BinaryTreeNode(data);
  //   this->root = node;
  // }
  //Find method for class BST
  bool find(int n,BinaryTreeNode* node){
    if(node==NULL) return false;
    if(node->data == n) return true;
    if(n<node->data)
    return find(n,node->left);
    else
    return find(n,node->right);
  }
  bool find(int n){
    return find(n, root);
  }
  //Insert method for class BST
  BinaryTreeNode* insert(int n,BinaryTreeNode* node){
    BinaryTreeNode* temp = new BinaryTreeNode(n);
      if(node == NULL) return temp;
      else{
        if(temp->data < node->data)
          if(node->left == NULL)
          node->left = temp;
          else
          insert(n,node->left);
        else
          if(node->right==NULL)
          node->right = temp;
          else
          insert(n,root->right);
      }
    return node;
  }
  void insert(int n){
      this->root = insert(n, root);
  }
  // Insert method for class BST
  BinaryTreeNode* erase(int n, BinaryTreeNode* node){
    BinaryTreeNode* temp{nullptr};
    if (node == NULL) return NULL;
    if(node->data == n){
      if (node->left == NULL && node->right == NULL){
        delete node;
        return NULL;
      }
      else if (node->left == NULL && node->right != NULL){
        temp = node->right;
        node = NULL;
        return temp;
      }
      else if (node->right == NULL && node->left != NULL){
        temp = node->left;
        node = NULL;
        return temp;
      }
      else{
        BinaryTreeNode* temp = root->right;
        while(temp->left != NULL) temp = temp->left;
        node->data = temp->data;
        erase(temp->data,root->right);
        return node;
      }
    }
    else if(n < node->data){
      node->left = erase(n, node->left);
      return node;
    }
    else if(n > node->data){
      node->right = erase(n, node->right);
      return node;
    }
    return node;
  }
  void erase(int n){
    this->root = erase(n, root);
  }
};
