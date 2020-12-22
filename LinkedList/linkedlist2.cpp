#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int main(){
  Node* head = Input();
  display(head);
  head = reverse(head);
  display(head);
  // head = insert(head,5,99);
  // head = insert(head,6,98);
  // head = insert(head,7,97);
  // head = insert(head,10,999);

  // display(head);
  return 0;

}
