#include <bits/stdc++.h>
using namespace std;
int kadane(int arr[], int size){
  int maximum = INT_MIN;
  int max_so_far = 0;
  int best_so_far = 0;
  for (int i = 0; i < size; i++){
    if(arr[i] > maximum){
      maximum = arr[i];
    }
    max_so_far += arr[i];
    if(max_so_far < 0){
      max_so_far = 0;
    }
    if(max_so_far > best_so_far){
      best_so_far = max_so_far;
    }
  }
  return (best_so_far>0)? best_so_far: maximum;
}
int main(){
  int arr[]{1,-1,-2,-3,-4,-5};
  cout<< kadane(arr, 5) <<endl;
  return 0;
}
