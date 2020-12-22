#include <bits/stdc++.h>
using namespace std;
int LCS(string s,string t){
  if(s.size() == 0 || t.size() == 0){
    return 0;
  }
  if(s[0] == t[0]){
    return  1 + LCS(s.substr(1),t.substr(1));
  }
  else{
    return max(LCS(s,t.substr(1)), LCS(s.substr(1),t));
  }
}
int main(){
  string s = "a";
  string t = "zxb";
  // cin>>s>>t;
  cout<<LCS(s,t);
  return 0;
}
