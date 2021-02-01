// Leetcode alphacode or decode ways
#include <bits/stdc++.h>
using namespace std;
inline int strToInt(char s0, char s1){
  int range;
  char str[3] = {s0,s1};
  sscanf(str,"%d",&range);
  return range;
}

int numDecodings(int *memo,string s, int size, int i = 0){
  if(i >= size)
    return 1;
  if(memo[size-i-1] != -1){
    return memo[size-i-1];
  }
  int n=0, m=0, range = 0;
  if((size-i >= 2) && (s[i+2] != '0')){
    range = strToInt(s[i], s[i+1]);
    if(range >=10 && range<=26)
      m = numDecodings(memo,s,size,i+2);
  }

  if(s[i]!= '0' && s[i+1] != '0'){
    n =  numDecodings(memo,s,size,i+1);
  }
  memo[size-i-1] = n+m;
  return memo[size-i-1];
}
int numDecodings(string s){
  int size = s.size();
  int *memo = new int[size + 1];
  for(int i=0;i<=size;i++){
    memo[i] = -1;
  }
  return numDecodings(memo,s,size,0);
}
int main(){
  string s;
  cin >> s;
  cout << numDecodings(s);
  return 0;
}
