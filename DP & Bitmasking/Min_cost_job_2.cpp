#include <bits/stdc++.h>
using namespace std;
int minCost(int*dp,int cost[4][4],int n,int p,int mask){
  if(p>=n){
    return 0;
  }
  if(dp[mask] != 0){
    return dp[mask];
  }
  int ans;
  int minimum = INT_MAX;
  for(int j=0;j<n;j++){
    if(!(mask&(1<<j))){
      ans = minCost(dp,cost,n,p+1,mask|(1<<j)) + cost[p][j];
      minimum = min(ans,minimum);
    }
  }
  return dp[mask] = minimum;
}
int main(){
  #ifndef ONLINE_JUDGE
    freopen("F://C++//input.txt", "r", stdin);
    freopen("F://C++//output.txt", "w", stdout);
  #endif
  int n;
  cin>>n;
  int cost[4][4];
  int *dp = new int[(1<<n)];
  for(int i=0;i<(1<<n);i++){
    dp[i] = 0;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>cost[i][j];
    }
  }
  cout<<minCost(dp, cost,4,0,0);
  return 0;
}
