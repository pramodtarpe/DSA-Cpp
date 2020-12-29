#include <bits/stdc++.h>
using namespace std;
int minCost(int **memo,int **arr,int i,int j,int m, int n){
  if(i==m-1 && j==n-1){
    memo[i][j] = arr[i][j];
    return memo[i][j];
  }
  int c1 = INT_MAX,c2 = INT_MAX,c3 = INT_MAX;
  if(i+1<m && j<n){
    if(memo[i+1][j] == INT_MAX){
      memo[i+1][j]=minCost(memo,arr,i+1,j,m,n);
    }
    c1 = memo[i+1][j];
  }
  if(i<m && j+1<n){
    if(memo[i][j+1] == INT_MAX){
      memo[i][j+1]=minCost(memo,arr,i,j+1,m,n);
    }
    c1 = memo[i][j+1];
  }
  if(i+1<m && j+1<n){
    if(memo[i+1][j+1] == INT_MAX){
      memo[i+1][j+1]=minCost(memo,arr,i+1,j+1,m,n);
    }
    c1 = memo[i+1][j+1];
  }
  memo[i][j] =arr[i][j] + min(c1,min(c2,c3));
  return memo[i][j];
}
int minCost(int **arr, int m,int n){
  int **memo =new int*[m];
  for(int i=0;i<m;i++){
    int *arr = new int[n];
    fill(arr,arr+n,INT_MAX);
    memo[i] = arr;
  }
  return minCost(memo,arr,0,0,m,n);
}
int main(){
  int m=10000,n=10000;
  int **arr = new int*[m];
  for(int i=0;i<m;i++){
    int *a = new int[n];
    for(int i=0;i<n;i++)
      a[i] = i+1;
    arr[i] = a;
  }

  cout<< minCost(arr,m,n);
  return 0;
}
