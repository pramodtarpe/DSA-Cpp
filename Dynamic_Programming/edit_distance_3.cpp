#include <bits/stdc++.h>
using namespace std;
int editDistance(string s, string t){
  int m = s.size();
  int n = t.size();
  int **dp = new int*[m+1];
  for(int i=0;i<=m;i++){
    dp[i] = new int[n+1];
  }

  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
      if(i==0){
        dp[i][j] = j;
      }
      else if(j==0){
        dp[i][j] = i;
      }
      else if(s[i-1] == t[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }
      else{
        dp[i][j] =1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
      }
    }
  }
  return dp[m][n];
}

int main(){
  string s = "domarp";
  string t = "pramod";
  cout<<editDistance(s,t);
  return 0;
}
