//top down approach
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

ull fibo(ull n){
  ull *dp = new ull[n+1];
  dp[0] = 0;
  dp[1] = 1;
  for(int i=2;i<=n;i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}
int main(){
  ull n;
  cin>>n;
  cout<<fibo(n)<< endl;
  return 0;
}
