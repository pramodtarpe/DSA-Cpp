#include <bits/stdc++.h>
using namespace std;
int LCS(string s, string t){
  int slen = s.size();
  int tlen = t.size();
  int **dp = new int*[slen+1];
  for(int i=0;i<=slen;i++){
    dp[i] = new int[tlen+1];
  }
  for(int i=0;i<=s.size();i++){
    dp[i][0] = 0;
  }
  for(int j=0;j<=t.size();j++){
    dp[0][j] = 0;
  }
  for(int i=1;i<=s.size();i++){
    for(int j=1;j<=t.size();j++){
      if(s[slen-i] == t[tlen-j]){
        dp[i][j] = dp[i-1][j-1]+1;
      }
      else{
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
      }
    }
  }
  return dp[slen][tlen];
}
int main(){
  string s = "pramod";
  string t = "pramod";

  cout<<LCS(s,t);
  return 0;
}
