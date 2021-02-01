#include <bits/stdc++.h>
using namespace std;
class Parent{
public:
  virtual void print(){
    cout<<"I am parent"<<endl;
  }
};

class Child : public Parent{
public:
  void print(){
    cout<<"I am child"<<endl;
  }
};

int main(){
  Parent *p;
  Child c;
  p = &c;
  p->print();
  return 0;
}
