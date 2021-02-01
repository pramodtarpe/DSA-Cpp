#include <iostream>
using namespace std;
class Vehicle{
private:
  int cost;
public:
  int speed;
  Vehicle(int value,int cost){
    this->cost = cost;
    this->speed = value;
  }
  void print(){
    cout<< "Speed: " << speed <<endl;
  }
};

class Car: public Vehicle{
public:
  Car(int value){
    this->speed = value;
  }
};

int main(){
	Car c(11);
  c.print();

  return 0;
}
