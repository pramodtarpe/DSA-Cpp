#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int start, int end){
    int pivot = arr[start];
    int pos = start;
    for(int i=start+1;i<=end;i++){
        if(pivot > arr[i]){
         pos++;
         swap(arr[pos], arr[i]);
        }
    }
    swap(arr[start], arr[pos]);
    return pos;
}

void quickSort(int a[],int start,int end){
  if(start<end){
    int pos=partition(a,start,end);
    quickSort(a,start,pos-1);
    quickSort(a,pos+1,end);
  }
}

void printArray(int arr[],int size){
  for (int i=0;i<size;i++) cout<<arr[i]<<" ";
  cout<<endl;
}
int main(){
    int size;
    cin>>size;
    int *arr = new int[size];
    for(int i=0;i<size;i++){
        arr[i] = size-i;
    }
    quickSort(arr,0,size-1);
    printArray(arr,size);
}
