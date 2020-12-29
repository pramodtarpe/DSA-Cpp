// Count all possible paths from top left to bottom right of a mXn matrix
#include <bits/stdc++.h>
using namespace std;
int allWays(int n, int m){
  if(n < 1 || m < 1){
    return 0;
  }
  if(n==1 && m==1){
    return 1;
  }
  return allWays(n-1,m) + allWays(n, m-1);
}
int main(){
  int n,m;
  cin>>n>>m;
  cout<< allWays(n, m)<<endl;
  return 0;
}
