#include <bits/stdc++.h>
using namespace std;
int coinChange(int n, int arr[], int size){
 if(n == 0){
   return 1;
 }
 if(n < 0){
   return 0;
 }
 if(size == 0){
   return 0;
 }
 return coinChange(n-arr[0],arr,size) + coinChange(n,arr+1,size-1);
}

int main(){
  int n;
  cin >> n;
  int arr[]{1};
  cout<< coinChange(n, arr, 1);
  return 0;
}
