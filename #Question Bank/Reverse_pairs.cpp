#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr,int l,int mid,int r){
  int i,j,rev_pairs=0;
  j=mid+1;
  for(i=l;i<=mid;i++){
    while((j<=r) && (arr[i]>2LL*arr[j])){
      j++;
    }
    rev_pairs += j-(mid+1);
  }
  vector<int> temp;
  i = l;
  j = mid+1;
  while((i<=mid) && (j<=r)){
    if(arr[i] <= arr[j]){
      temp.push_back(arr[i++]);
    }
    else{
      temp.push_back(arr[j++]);
    }
  }
  while(i<=mid)
    temp.push_back(arr[i++]);
  while(j<=r)
    temp.push_back(arr[j++]);
  for(i=l;i<=r;i++){
    arr[i] = temp[i-l];
  }
  return rev_pairs;
}

int mergeSort(vector<int> &arr,int l,int r){
  int rev_pairs = 0;
  if(r > l){
    int mid = l + (r-l)/2;
    rev_pairs += mergeSort(arr,l,mid);
    rev_pairs += mergeSort(arr,mid+1,r);
    rev_pairs += merge(arr,l,mid,r);
  }
  return rev_pairs;
}
int reversePairs(vector<int> &arr){
  return mergeSort(arr,0,arr.size()-1);
}

int main(){
  vector<int> arr = {2,4,3,5,1};
  cout<<reversePairs(arr);
  return 0;
}
