#include <bits/stdc++.h>
using namespace std;
class Car{
public:
  void print();
};

class Vehicle{
  string name = "Vehicle";
  friend void Car::print();
  friend void func();
};
void Car::print(){
  Vehicle v;
  cout<< v.name <<endl;
}
void func(){
  Vehicle v;
  cout<< "Global: " << v.name <<endl;
}

int main(){
  Car c;
  c.print();
  func();
  return 0;
}
