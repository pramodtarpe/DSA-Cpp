#include <bits/stdc++.h>
#include<vector>
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

int main(){
  Node n1(1);
  Node n2(2);
  Node n3(1);
  Node n4(2);
  Node n5(3);
  //
  Node* head = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  //print linked list
  display(head);

}
