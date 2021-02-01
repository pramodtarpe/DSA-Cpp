#include <bits/stdc++.h>
using namespace std;
int countSetBit(int n){
  int count = 0;
  while(n>0){
    count++;
    n = n&(n-1);
  }
  return count;
}
int minCost(int **cost,int n){
  int *dp = new int[(1<<n)];
  for(int i=0;i<(1<<n);i++){
    dp[i] = INT_MAX;
  }
  dp[0] = 0;
  for(int mask=0;mask<(1<<n);mask++){
    int k = countSetBit(mask);
    for(int j=0;j<n;j++){
      if(!(mask&(1<<j))){
        dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask]+cost[k][j]);
      }
    }
  }
  return dp[(1<<n)-1];
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("F://C++//input.txt", "r", stdin);
    freopen("F://C++//output.txt", "w", stdout);
  #endif
  int n;
  cin>>n;
  int **cost = new int*[n];
  for(int i=0;i<n;i++){
    cost[i] = new int[n];
    for(int j=0;j<n;j++){
      cin>>cost[i][j];
    }
  }
  cout<<minCost(cost,4);
  return 0;
}
