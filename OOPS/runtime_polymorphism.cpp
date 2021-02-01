#include <bits/stdc++.h>
using namespace std;
class Employee{
public:
  int work_days;
  virtual void salary(){
    cout<<"Employee"<<endl;
  }
};
class Teacher : public Employee{
public:
  int work_days;
  Teacher(int work_days){
    this->work_days = work_days;
  }
  void salary(){
    cout<<"Employee salary: "<<(this->work_days * 100)<< endl;
  }
};
class Principal : public Employee{
public:
  Principal(int work_days){
    this->work_days = work_days;
  }
  void salary() {
    cout<<"Principal salary: "<<this->work_days * 1000<< endl;
  }
};
class Staff : public Employee{
public:
  Staff(int work_days){
    this->work_days = work_days;
  }
  void salary() {
    cout<<"Staff salary: "<<this->work_days * 25<< endl;
  }
};

int main(){
  Employee* arr[5];
  Principal principal(30);
  Teacher teacher(30);
  Staff staff_1(30);
  Staff staff_2(30);
  Staff staff_3(30);
  arr[0] = &principal;
  arr[1] = &teacher;
  arr[2] = &staff_1;
  arr[3] = &staff_2;
  arr[4] = &staff_3;
  for(int i=0;i<5;i++){
    arr[i]->salary();
  }
  return 0;
}
