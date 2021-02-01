#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int arr[n];
  int ans = 0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  int minimum = 0;
  int j = n-1;
  while(j>=0){
    int root = sqrt(arr[j]);
    for(int mul=root;mul>=2;mul--){
      if(arr[j]%mul == 0 && (arr[minimum]*mul <= arr[j])){
        arr[j] = arr[j]/mul;
        arr[minimum] = arr[minimum]*mul;
        j--;
        if(arr[minimum] > arr[minimum+1]){
          minimum +=1;
        }
        if(arr[minimum] > arr[minimum-1] && minimum > 0){
          minimum -=1;
        }
        break;
      }
    }
    j--;
  }
  for(int i=0;i<n;i++) ans+=arr[i];
  cout<<ans<<endl;
  return 0;
}
