#include <bits/stdc++.h>
using namespace std;
int minCost(int **arr,int m, int n){
  int **dp =new int*[m];
  for(int i=0;i<m;i++){
    dp[i] = new int[n];
  }
  dp[m-1][n-1] = arr[m-1][n-1];
  for(int i=m-2;i>=0;i--){
    dp[i][n-1] = arr[i][n-1] + dp[i+1][n-1];
  }
  for(int j=n-2;j>=0;j--){
    dp[m-1][j] = arr[m-1][j] + dp[m-1][j+1];
  }

  for(int i=m-2;i>=0;i--){
    for(int j=n-2;j>=0;j--){
      int c1=dp[i+1][j],c2=dp[i][j+1],c3=dp[i+1][j+1];
      dp[i][j] = arr[i][j] + min(c1,min(c2,c3));
    }
  }
  return dp[0][0];
}
int main(){
  int m=10000,n=10000;
  int **arr = new int*[m];
  for(int i=0;i<m;i++){
    int *a = new int[n];
    for(int i=0;i<n;i++)
      a[i] = i+1;
    arr[i] = a;
  }

  cout<< minCost(arr,m,n);
  return 0;
}
