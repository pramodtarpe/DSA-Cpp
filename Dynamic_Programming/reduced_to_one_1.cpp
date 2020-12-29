//brute force
#include <bits/stdc++.h>
using namespace std;
int reduce(int n){
  if(n==1){
    return 0;
  }
  int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
  if(n>1){
    c1 = reduce(n-1);
  }
  if(n%2==0){
    c2 = reduce(n/2);
  }
  if(n%3==0){
    c3 = reduce(n/3);
  }
  return 1 + min(c1,min(c2,c3));
}
int main(){
  int n;
  cin>>n;
  cout<<reduce(n);
  return 0;
}
