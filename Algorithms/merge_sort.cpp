#include<iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end){
  int temp[end-start+1];
  for(int i=0;i<(end-start+1);i++)
    temp[i] = arr[start+i];
  int i,j,k;
  i=start;
  j=mid+1;
  k=start;
  while((i<=mid) && (j<=end)){
    if(temp[i-start] <= temp[j-start]){
      arr[k++] = temp[i-start];
      i++;
    }
    else{
      arr[k++] = temp[j-start];
      j++;
    }
  }
  while(i<=mid){
    arr[k++] = temp[(i-start)];
    i++;
  }
  while(j<=end){
    arr[k++] = temp[(j-start)];
    j++;
  }
}

void merge_sort(int arr[],int start,int end){
  if (start>=end) return;
  int mid = start+(end-start)/2;

  merge_sort(arr,start,mid);
  merge_sort(arr,mid+1,end);

  merge(arr,start,mid,end);
}

void printArray(int arr[],int size){
  for (int i=0;i<size;i++) cout<<arr[i]<<" ";
  cout<<endl;
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++) cin>>arr[i];
    merge_sort(arr,0,size-1);
    printArray(arr,size);
}
