#include<bits/stdc++.h>
using namespace std;
struct Fraction{
  //data members
  int numerator;
  int denominator;
  //constructor
  Fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
  }
  //methods
  void display(){
    cout<< numerator <<"/"<<denominator<<endl;
  }
  //operator overloading of Fraction class
  void simplify(){
    int div = __gcd(numerator, denominator);
    numerator = numerator/div;
    denominator = denominator/div;
  }
  Fraction operator+(const Fraction &f2){
    int n= ((numerator*f2.denominator) + (denominator*f2.numerator));
    int d= (denominator)*(f2.denominator);
    Fraction f3(n,d);
    f3.simplify();
    return f3;
  }
};

int main(){
  Fraction f1(100,200);
  Fraction f2(0,1);
  Fraction f3 = f1+f2;
  f1.display();
  f2.display();
  f3.display();
  return 0;
}
