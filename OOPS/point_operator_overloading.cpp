#include<iostream>
#include<cmath>
using namespace std;
template<typename T>
struct Point{
  //data members
  T x;
  T y;
  //constructor
  Point(int x, int y){
    this->x = x;
    this->y = y;
  }
  //operator overloading
  double operator+(const Point &p2){
    double dist = 0;
    dist = sqrt((x-p2.x)*(x-p2.x) + (y-p2.y)*(y-p2.y));
    return dist;
  }
};

int main(){
  Point<double> p1(5.0,0.0);
  Point<double> p2(0.0,7.0);
  cout<<p1+p2;
}
