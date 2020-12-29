#include <bits/stdc++.h>
using namespace std;
int editDistance(int **memo, string s, string t, int i, int j){
  if(i == 0 || j == 0){
    return max(i,j);
  }
  if(memo[i][j] != -1){
    return memo[i][j];
  }
  if(s[i-1] == t[j-1]){
    memo[i][j] = editDistance(memo,s, t,i-1,j-1);
    return memo[i][j];
  }
  else{
    memo[i][j] = 1 + min((editDistance(memo,s,t,i-1,j)), min(editDistance(memo,s,t,i,j-1), editDistance(memo,s,t,i-1,j-1)));
    return memo[i][j];
  }
}
int editDistance(string s, string t){
  int **memo = new int*[s.size()+1];
  for(int i=0;i<=s.size();i++){
    memo[i] = new int[t.size()+1];
    for(int j=0;j<=t.size();j++) memo[i][j] = -1;
  }
  return editDistance(memo, s, t, s.size(), t.size());
}
int main(){
  string s = "b";
  string t = "a";
  cout<<editDistance(s,t);
  return 0;
}
