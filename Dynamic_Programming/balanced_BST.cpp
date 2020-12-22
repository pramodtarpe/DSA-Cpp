#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
ull balancedBT(int h){
  if(h<=1){
    return 1;
  }
  ull x = balancedBT(h-1);
  ull y = balancedBT(h-2);
  return (x*x) + (2*x*y);
}

int main(){
  ull h;
  cin>>h;
  cout<< balancedBT(h);
  return 0;
}
