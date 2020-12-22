#include<iostream>
using namespace std;

class Vehicle{
public:
  int speed;
  Vehicle(){
    speed = 0;
    cout<<"Vehicle Default Constructor"<<endl;
  }
  Vehicle(int speed){
    this->speed = speed;
    cout<<"Vehicle Parameterized Constructor"<<endl;
  }
  ~Vehicle(){
    cout<<"Vehicle Default Destructor"<<endl;
  }
};
class Car : public Vehicle{
public:
  Car(){
    speed = 0;
    cout<<"Car Default Constructor"<<endl;
  }
  Car(int speed) : Vehicle(speed){
    cout<<"Car Parameterized Constructor"<<endl;
  }
  ~Car(){
    cout<<"Car Default Destructor"<<endl;
  }
};
int main(){
  // Vehicle v;
  Car c(500);
  cout<<"Speed: " <<c.speed <<endl;
  return 0;
}
