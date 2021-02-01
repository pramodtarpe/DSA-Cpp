#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main(){
  FASTIO
  map<int,int> data;
  int a,b,c;
  cin>>a>>b>>c;
  int arr[a+b+c];
  for(int i=0;i<a+b+c;i++) cin>>arr[i];
  sort(arr,arr + (a+b+c));
  int count = 0;
  for(int i=1; i<a+b+c;i++){
    if(arr[i] == arr[i-1] && arr[i] != arr[i+1]){
      count ++;
    }
  }
  cout<<count<<endl;
  for(int i=1; i<a+b+c;i++){
    if(arr[i] == arr[i-1] && arr[i] != arr[i+1])
      cout<<arr[i]<<endl;
  }
  return 0;
}
