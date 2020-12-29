// Count all possible paths from top left to bottom right of a mXn matrix
#include <bits/stdc++.h>
using namespace std;
int allWays(int **memo, int n, int m,int i=0, int j=0){
  if(i > n || j > m){
    return 0;
  }
  if(i==n && j==m){
    memo[i][j] = 1;
    return 1;
  }
  if(memo[n][m] != -1){
    return memo[n][m];
  }
  memo[i][j+1] = allWays(memo, n, m,i,j+1);
  memo[i+1][j] = allWays(memo, n, m,i+1,j);
  memo[i][j] = memo[i][j+1] + memo[i+1][j];
  return memo[i][j];
}
int main(){
  int n,m;
  cin>>n>>m;
  int **memo = new int*[n+1];
  for(int i=0;i<n;i++){
    memo[i] = new int[m+1];
    for(int j=0;j<m;j++) memo[i][j] = -1;
  }
  cout<<allWays(memo, n, m)<<endl;
  return 0;
}
