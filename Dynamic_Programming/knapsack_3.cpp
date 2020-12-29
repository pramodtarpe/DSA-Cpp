#include <bits/stdc++.h>
using namespace std;
int knapsack(int weight[], int value[],int N, int W){
  int **dp = new int*[N+1];
  for(int i=0;i<=N;i++){
    dp[i] = new int[W+1];
  }
  for(int i=0;i<=N;i++){
    dp[i][0] = 0;
  }
  for(int j=0;j<=W;j++){
    dp[0][j] = 0;
  }
  for(int i=1;i<=N;i++){
    for(int w=1;w<=W;w++){
      if(weight[i-1] <= w){
        dp[i][w] = max(dp[i-1][w], value[i-1] + dp[i-1][w-weight[i-1]]);
      }
      else{
        dp[i][w] = dp[i-1][w];
      }
    }
  }
  return dp[N][W];
}
int main(){
  int N = 10;
  int value[]{1,2,3,4,5,6,7,8,9,10};
  int weight[]{1,2,3,4,5,6,7,8,9,10};
  int W = 55;
  cout<< knapsack(weight,value,N,W);
  return 0;
}
