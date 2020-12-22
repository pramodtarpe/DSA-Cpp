#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;
#define range(n) for(int i=0;i<n;i++)
#define __range(start,end) for(int i=start;i<=end;i++)
#define in(n,arr) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr) for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++) cout<<arr[i]<<" ";cout<<endl;
#define sort(arr) sort(arr,arr+sizeof(arr)/sizeof(arr[0]))
#define all(V) for(auto i=V.begin();i != V.end(); i++) cout<<*i<<" ";cout<<endl;

using namespace std;

int main(){
  FASTIO
  int n,d;
  cin>>n>>d;
  int arr[n];
  in(n,arr);
  sort(arr);
  int count = 0;
  int i=0;
  while(i < n){
    if (abs(arr[i] - arr[i+1]) <= d){
      count++;
      i +=2;
    }
    else i++;
  }
  cout<<count<<endl;
  return 0;
}
