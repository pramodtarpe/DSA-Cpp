#include <bits/stdc++.h>
#include "Priority.h"
using namespace std;

int main(){
  PriorityQueue myqueue;
  myqueue.insert(-10);
  myqueue.insert(-20);
  myqueue.insert(-30);
  myqueue.insert(-40);
  myqueue.insert(-50);
  myqueue.insert(-60);

  cout<<myqueue.getSize()<<endl;

  while(!myqueue.isEmpty()){
    cout<<-myqueue.removeMin()<<" ";
  }

  return 0;
}
