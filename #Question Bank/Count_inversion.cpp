// Enhanced mergeSort
#include <bits/stdc++.h>
using namespace std;
long long merge(long long arr[],long long temp[],long long l,long long mid, long long r){
  long long i,j,k;
  long long invcount=0;
  i=l;
  j=mid+1;
  k=l;
  while((i<=mid) && (j<=r)){
    if(arr[i] <= arr[j]){
      temp[k++] = arr[i++];
    }
    else{
      temp[k++] = arr[j++];
      invcount += mid-i+1;
    }
  }
  while(i<=mid){
    temp[k++] = arr[i++];
  }
  while(j<=r){
    temp[k++] = arr[j++];
  }
  for(i = l;i<=r;i++){
    arr[i] = temp[i];
  }
  return invcount;
}
long long mergeSort(long long arr[],long long temp[],long long l,long long r){
  long long mid,invcount = 0;
  if(r>l){
    mid = l + (r-l)/2;
    invcount += mergeSort(arr,temp,l,mid);
    invcount += mergeSort(arr,temp,mid+1,r);
    invcount += merge(arr,temp,l,mid,r);
  }
  return invcount;
}

long long inversionCount(long long arr[], long long n){
  long long temp[n];
  return mergeSort(arr,temp,0,n-1);
}

int main(){
  long long n = 5;
  long long arr[5] = {2,4,1,3,5};
  cout<<inversionCount(arr,5)<<endl;

  return 0;
}
