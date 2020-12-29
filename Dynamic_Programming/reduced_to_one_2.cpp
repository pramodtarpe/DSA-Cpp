#include <bits/stdc++.h>
using namespace std;
int reduce(int n,int memo[]){
  if(n==1){
    memo[1] = 0;
    return 0;
  }
  int c2=INT_MAX,c3=INT_MAX;
  if(memo[n-1] == -1){
    memo[n-1] = reduce(n-1,memo);
  }
  if(n%2==0 ){
    if(memo[n/3] == -1)
    memo[n/2] = reduce(n/2,memo);
    c2 = memo[n/2];
  }
  if(n%3==0 ){
    if(memo[n/3] == -1)
    memo[n/3] = reduce(n/3,memo);
    c3 = memo[n/3];
  }
  memo[n] = 1 + min(memo[n-1],min(c2,c3));
  return memo[n];
}
int reduce(int n){
  int memo[n+1];
  fill(memo,memo+n+1,-1);
  return reduce(n,memo);
}
int main(){
  int n;
  cin>>n;
  cout<<reduce(n);
  return 0;
}
