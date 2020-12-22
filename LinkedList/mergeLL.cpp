#include <bits/stdc++.h>
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
void display(Node* head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}
Node* Input(){
  Node* head = NULL;
  Node* tail = NULL;
  int data;
  cin>>data;
  while(data != -1){
    Node* newnode = new Node(data);
    if(head == NULL){
      head = newnode;
      tail = newnode;
    }
    else{
      tail->next = newnode;
      tail = newnode;
    }
    cin>>data;
  }
  return head;
}
Node* merge(Node* h1,Node*h2){

}
int main(){
  Node* head1 = Input();
  Node* head2 = Input();
  Node* head = merge(head1,head2);
  display(head);
  return 0;
}
