#include<iostream>
using namespace std;

void printArray(int arr[],int size){
  for (int i=0;i<size;i++) cout<<arr[i]<<" ";
  cout<<endl;
}

void insertionSort(int a[],int size){
  for (int i=1;i<size;i++){
    int current=a[i];
    int j=i-1;
    for (;j>=0;j--){
      if (current<a[j]){
      a[j+1]=a[j];
    }
      else break;
    }
    a[j+1] = current;
  }
}

int main(){
  int size;
  cin>>size;
  int *arr = new int[size];
  for(int i=0;i<size;i++) cin>>arr[i];
  insertionSort(arr,size);
  printArray(arr,size);
  delete []arr;
}
