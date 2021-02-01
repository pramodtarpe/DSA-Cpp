// longest dpresing subsequence
#include <bits/stdc++.h>
using namespace std;
int LIS(int arr[], int n){
  if(n <= 1)
      return n;
  int dp[n];
  for(int i = 0; i < n ;i++)
      dp[i] = 1;
  for(int i = 1; i < n ;i ++){
      for(int j = 0; j < i; j++){
          if(arr[j] < arr[i])
              dp[i] = max(dp[j]+1, dp[i]);
      }
  }
  return *max_element(dp, dp+n);
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cout<<LIS(arr, n);
  return 0;
}
