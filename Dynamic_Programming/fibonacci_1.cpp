//top down approach
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

ull fibo(ull n,ull *dp){
  if(n<=1){
    dp[n] = n;
    return n;
  }
  if(dp[n-1] == 0){
    dp[n-1] = fibo(n-1,dp);
  }
  if(dp[n-2] == 0){
    dp[n-2] = fibo(n-2,dp);
  }
  return dp[n-1]+dp[n-2];
}
ull fibo(ull n){
  ull *dp = new ull[n+1];
  fill(dp,dp+n+1,0);
  return fibo(n,dp);
}
int main(){
  ull n;
  cin>>n;
  cout<<fibo(n)<< endl;
  return 0;
}
