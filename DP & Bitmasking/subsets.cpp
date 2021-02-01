// Bit masking
#include <bits/stdc++.h>
using namespace std;
void subset(int arr[],int n){
  int end = (1<<n);
  for(int mask=0;mask<end;mask++){
    for(int i=0;i<n;i++){
      if((mask>>i)&1 == 1){
        cout<<arr[i]<<" ";
      }
    }
    cout<<endl;
  }
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  subset(arr,n);
  return 0;
}
