#include <bits/stdc++.h>
using namespace std;
int minCost(int **arr,int i,int j,int m, int n){
  if(i==m-1 && j==n-1){
    return arr[i][j];
  }
  int c1 = INT_MAX,c2 = INT_MAX,c3 = INT_MAX;
  if(i+1<m && j<n)
  c1=minCost(arr,i+1,j,m,n);
  if(i<m && j+1<n)
  c2=minCost(arr,i,j+1,m,n);
  if(i+1<m && j+1<n)
  c3=minCost(arr,i+1,j+1,m,n);

  return arr[i][j] + min(c1,min(c2,c3));
}
int minCost(int **arr, int m,int n){
  return minCost(arr,0,0,m,n);
}
int main(){
  // int m = 3,n = 4;
  // int **arr = new int*[3];
  // arr[0] =new int[4]{5,0,4,10};
  // arr[1] =new int[4]{8,2,0,5};
  // arr[2] =new int[4]{10,0,6,8};
  int m=100,n=100;
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
