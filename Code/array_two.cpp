#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;
#define range(n) for(int i=0;i<n;i++)
#define range_inc(n,m) for(int i=n;i<=m;i++)
#define in(n,arr) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr) for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++) cout<<arr[i]<<" ";cout<<endl;
#define all(V) for(auto i=V.begin();i != V.end(); i++) cout<<*i<<" ";cout<<endl;

using namespace std;

int main(){
  FASTIO
  vector<int> arr{1,2,3,4,5};
  for(auto i:arr) cout<<i<<" "<<endl;

  int n = 5;
  int k=3;
  int i=0;
  for(;i<(n-n%k);i+=k){
    reverse(arr.begin()+i, arr.begin()+i+k);
  }
  if(n%k > 0){
    n = n%k;
    reverse(arr.begin()+i, arr.end());
  }

  for(auto i:arr) cout<<i<<" ";
  return 0;
}
