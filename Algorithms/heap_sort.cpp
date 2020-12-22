#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i){
  int child = i;
  int LCI =2*i + 1;
  int RCI =2*i + 2;
  if(LCI < size && arr[LCI] > arr[child]){
    child = LCI;
  }
  if(RCI < size && arr[RCI] > arr[child]){
    child = RCI;
  }
  if(child != i){
    swap(arr[child], arr[i]);
    heapify(arr,size,child);
  }
}
void heap_sort(int arr[], int size){
  for(int i=(size/2)-1; i>=0; i--){
    heapify(arr,size,i);
  }
  for(int i=size-1;i>=1;i--){
    swap(arr[0], arr[i]);
    heapify(arr,i,0);
  }
}
void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
int main(){
  int size;
  cin>>size;
  int *arr = new int[size];
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
  heap_sort(arr, size);
  printArray(arr,size);
}
