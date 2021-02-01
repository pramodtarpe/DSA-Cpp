#include <bits/stdc++.h>
using namespace std;
int solve(int**dp,int a,int b){
  for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
      int l=0,r=0;
      if(i-2 >= 0 && j-1>=0){
        l = dp[i-2][j-1];
      }
      if(i-1>=0 && j-2>=0){
        r = dp[i-1][j-2];
      }
      if((i>0 && j>1) || (i>1 && j>0)){
        dp[i][j] = 1+max(l,r);
      }
    }
  }
  return dp[a][b];
}
int main(){
  int **dp = new int*[1000000000+1];
  for(int i=0;i<=1000000000;i++) {
    dp[i] = new int[1000000000+1];
  }
  int T;
  cin>>T;
  while(T--){
    int a, b;
    cin>>a>>b;
    for(int i=0;i<=a;i++){
      for(int j=0;j<=b;j++){
        dp[i][j] = 0;
      }
    }
    cout<<solve(dp,a,b)<<endl;
  }
  return 0;
}
