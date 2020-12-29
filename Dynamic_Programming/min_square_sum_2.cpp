#include <bits/stdc++.h>
using namespace std;
int minSquare(int n, int *memo){
  if(n==0){
    return 0;
  }
  if(memo[n] != 0){
    return memo[n];
  }
  int minimum = INT_MAX;
  for(int i=sqrt(n);i>=1;i--){
    memo[n-(i*i)] = minSquare((n-i*i), memo);
    minimum = min(minimum, memo[n-(i*i)]);
  }
  memo[n] = 1 + minimum;
  return memo[n];
}
int minSquare(int n){
  int *memo = new int[n+1];
  for(int i=0;i<=n;i++)
    memo[i] = 0;
  return minSquare(n,memo);
}
int main(){
  for(int n=0;n<=18;n++){
    cout<<minSquare(n)<<endl;
  }
  return 0;
}
