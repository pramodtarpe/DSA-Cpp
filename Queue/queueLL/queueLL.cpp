#include <bits/stdc++.h>
#include "queueLinkedList.h"
using namespace std;

int main(){
  Queue q1;
  q1.enqueue(10);
  q1.enqueue(20);
  q1.enqueue(30);
  cout<<q1.front()<<endl;
  q1.dequeue();
  cout<<q1.front()<<endl;
  q1.dequeue();
  cout<<q1.front()<<endl;
  q1.dequeue();
  cout<<q1.front()<<endl;
  q1.dequeue();
  return 0;
}
