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
  int size,q;
  cin>>size>>q;
  bool arr[size]{0};
  while (q--) {
    int x,a,b;
    cin>>x>>a>>b;
    if(x == 0){
      range_inc(a,b){
        arr[i] = (arr[i])? 0:1;
      }
    }
    if(x == 1){
      int count=0;
      range_inc(a,b){
        if(arr[i]) count++;
      }
      cout<<count<<endl;
    }
  }
  return 0;
}
