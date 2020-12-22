#include<iostream>
using namespace std;
class Node{
public:
  int data;
  Node *next=NULL;
public:
  Node(int data){
    this->data = data;
  }
};

class Queue{
private:
  int data;
  int size=0;
  Node* head=NULL;
  Node* tail=NULL;
public:
  int getSize(){
    return size;
  }
  void enqueue(int element){
    Node* newnode = new Node(element);
    if(size==0){
      head=newnode;
      tail=newnode;
    }
    else{
      tail->next=newnode;
      tail = newnode;
    }
    size++;
  }
  void dequeue(){
    if(size==0){
      cout<<"Queue empty"<<endl;
      return;
    }
    else{
      head = head->next;
    }
    size--;
  }
  int front(){
    return head->data;
  }
};
