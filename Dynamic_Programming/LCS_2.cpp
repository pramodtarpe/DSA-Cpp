#include <bits/stdc++.h>
using namespace std;
int LCS(int **memo, string s,string t){
  if(s.size() == 0 || t.size() == 0){
    memo[s.size()][t.size()] = 0;
    return 0;
  }
  if(memo[s.size()][t.size()] != -1){
    return memo[s.size()][t.size()];
  }
  if(s[0] == t[0]){
    memo[s.size()][t.size()] = 1 + LCS(memo, s.substr(1),t.substr(1));
    return memo[s.size()][t.size()];
  }
  else{
    memo[s.size()][t.size()] = max(LCS(memo, s.substr(1),t), LCS(memo, s,t.substr(1)));
    return memo[s.size()][t.size()];
  }
}
int LCS(string s, string t){
  int **memo = new int*[s.size()+1];
  for(int i=0;i<=s.size();i++){
    memo[i] = new int[t.size()+1];
    for(int j=0;j<=t.size();j++) memo[i][j] = -1;
  }
  return LCS(memo, s, t);
}
int main(){
  string s = "pramod";
  string t = "pramod";
  cout<<LCS(s,t);
  return 0;
}
