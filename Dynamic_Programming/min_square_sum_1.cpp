#include <bits/stdc++.h>
using namespace std;
int minSquare(int n){
  if(n==0){
    return 0;
  }
  int minimum = INT_MAX;
  for(int i=sqrt(n);i>=1;i--){
    minimum = min(minimum,minSquare(n-i*i));
  }
  return 1+minimum;
}
int main(){
  int n;
  cin>>n;
  cout<<minSquare(n);
  return 0;
}
