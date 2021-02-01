#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &memo ,vector<vector<int>> &arr,int n, int m, int i=0,int j=0){
  if(i == n-1 && j == m-1){
    if(arr[i][j] >= 0){
      return 1;
    }
    else{
      return abs(arr[i][j])+1;
    }
  }
  if(memo[i][j] != INT_MAX){
    return memo[i][j];
  }
  int down = INT_MAX,right = INT_MAX;
  if(i+1 < n && j<m){
    down = solve(memo,arr,n,m,i+1,j);
    if(arr[i][j] < down){
      down -= arr[i][j];
    }
    else{
      down = 1;
    }
  }
  if(i < n && j+1 < m){
    right = solve(memo,arr,n,m,i,j+1);
    if(arr[i][j] < right){
      right -= arr[i][j];
    }
    else{
      right = 1;
    }
  }
  memo[i][j] = min(down,right);
  return memo[i][j];
}
int main(){
  #ifndef ONLINE_JUDGE
    freopen("F://C++//input.txt", "r", stdin);
    freopen("F://C++//output.txt", "w", stdout);
  #endif
  int n,m;
  cin>>n>>m;
  vector<vector<int>> arr(n);
  vector<vector<int>> memo(n);

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int ele;
      cin >> ele;
      arr[i].push_back(ele);
      memo[i].push_back(INT_MAX);
    }
  }
  cout<<solve(memo,arr,n,m);
  return 0;
}
