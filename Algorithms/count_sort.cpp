#include <bits/stdc++.h>
using namespace std;
int* count(int arr[],int size){
  int count[101];
  int *output = new int[size+1];
  for(int i=0;i<=100;i++){
    count[i] = 0;
  }
  for(int i=0;i<size;i++){
    count[arr[i]] += 1;
  }
  for(int i=1;i<=100;i++){
   count[i] += count[i-1];
  }
  for(int i=0;i<size;i++){
    output[count[arr[i]]] = arr[i];
    count[arr[i]]--;
  }
  return output;
}
int main(){
  int size;
  cin>>size;
  int arr[size];
  for(int i=0;i<size;i++) cin>>arr[i];
  int *output = count(arr,size);
  for(int i=1;i<=size;i++) cout<<output[i]<<" ";
  cout<<endl;

  return 0;
}
