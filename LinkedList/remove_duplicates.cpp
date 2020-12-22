#include <bits/stdc++.h>
#include "LinkedList.h"
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;
//found
bool found(vector<int> vec , int  n){
  vector<int>:: iterator itr;
  itr = find(vec.begin(),vec.end(),n);
  if(itr != vec.end())
    return true;
  else
    return false;
}

//fuction here
Node* removeDuplicates(Node* head){
  vector<int> vec;
  vec.push_back(head->data);
  Node* temp = head->next;
  Node* prev = head;
  while(temp != NULL){
    if(!found(vec,temp->data)){
      vec.push_back(temp->data);
      prev = prev->next;
    }
    else{
      prev->next = temp->next;
    }
    temp = temp->next;
    }
  return head;
}
//
using namespace std;

int main(){
  FASTIO
  Node* head = inputLinkedList();
  display(head);
  head = removeDuplicates(head);
  display(head);

  return 0;
}
