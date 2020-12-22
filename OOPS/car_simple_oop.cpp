#include <iostream>
using namespace std;

class Car {
private:
  int maxSpeed{0};
public:
  Car(int maxSpeed){
    this->maxSpeed = maxSpeed;
  }
public:
    int speed();
    void setSpeed(int n);
};

int Car::speed() {
  return this->maxSpeed;
}
void Car::setSpeed(int n){
  maxSpeed = n;
}

int main() {
  Car obj1(200); // Create an object of Car
  Car obj2=obj1;
  obj1.setSpeed(99);
  obj2.setSpeed(99);

  cout << obj2.speed(); // Call the method with an argument
  return 0;
}
