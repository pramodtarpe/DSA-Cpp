#include <bits/stdc++.h>
using namespace std;

void waveSort(int a[],int size){
  for (int i=0;i<size;i+=2){
    // if(a[i]<a[i-1] && i>0) swap(a[i],a[i-1]);
    if(a[i]<a[i+1] && i<size-1) swap(a[i],a[i+1]);
  }
}

void printArray(int arr[],int size){
  for(int i=0;i<size;i++) cout<<arr[i]<<" ";
  cout<<endl;
}
int main(){
  int size;
  cin>>size;
  int *arr = new int[size];
  for(int i=0;i<size;i++) cin>>arr[i];
  waveSort(arr,size);
  printArray(arr,size);

  return 0;
}
