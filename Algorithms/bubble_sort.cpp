#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[],int size){
  for(int i=0;i<size-1;i++)
    for(int j=1;j<size-i;j++)
      if(a[j-1]>a[j])
        swap(a[j-1],a[j]);
}
void printArray(int arr[],int size){
  for (int i=0;i<size;i++) cout<<arr[i]<<" ";
  cout<<endl;
}
int main(){
  int arr[]{5,4,3,2,1};
  bubbleSort(arr,5);
  printArray(arr,5);
  return 0;
}
