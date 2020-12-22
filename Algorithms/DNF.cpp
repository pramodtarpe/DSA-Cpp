#include <bits/stdc++.h>
using namespace std;
void DNF(int arr[], int size){
  int low=0,mid=0,high=size-1;
  while(mid <= high){
    switch (arr[mid]) {
      case 0:
        swap(arr[low++],arr[mid++]);
        break;
      case 1:
        mid++;
        break;
      case 2:
        swap(arr[high--],arr[mid]);
        break;
    }
  }
}

int main(){
  int size;
  cin>>size;
  int arr[size];
  for(int i=0;i<size;i++)
    cin>>arr[i];
  DNF(arr,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}
