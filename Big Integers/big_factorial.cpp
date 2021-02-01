#include <bits/stdc++.h>
using namespace std;
void multiply(int *arr,int &n,int no){
  int carry = 0;
  for(int i=0;i<n;i++){
    int product = carry + arr[i] * no;
    carry = product/10;
    arr[i] = product%10;
  }
  while(carry){
    arr[n] = carry%10;
    carry = carry/10;
    n++;
  }
}
void bigFactorial(int number){
  int* arr = new int[1000000];
  for(int i=0;i<1000000;i++){
    arr[i] = 0;
  }
  arr[0] = 1;
  int n = 1;
  for(int i=2;i<=number;i++){
    multiply(arr,n,i);
  }
  for(int i = --n;i>=0;i--){
    cout<<arr[i];
  }
  cout<<endl;
}
int main(){
  int n;
  cin>>n;
  bigFactorial(n);
  return 0;
}
