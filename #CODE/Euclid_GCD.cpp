#include <bits/stdc++.h>
using namespace std;
int euclidGcd(int a,int b){
  return (b==0)? a: euclidGcd(b,a%b);
}
int lcm(int a,int b){
  return a*b/euclidGcd(a,b);
}
int main(){
  cout<<"GCD: "<<euclidGcd(9,9999999)<<endl;
  cout<<"LCM: "<<lcm(1000000000,2)<<endl;
  return 0;
}
