#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;
#define range(n) for(int i=0;i<n;i++)
#define in_range(n,m) for(int i=n;i<=m;i++)
#define in(n,arr) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr) for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++) cout<<arr[i]<<" ";cout<<endl;
#define all(V) for(auto i=V.begin();i != V.end(); i++) cout<<*i<<" ";cout<<endl;

using namespace std;

int main(){
  FASTIO
  int T;
  cin>>T;
  while(T--){
    int n,res = INT_MAX;
    cin>>n;
    in_range(1,sqrt(n)){
      if(n%i==0){
        res = min(res, abs((n/i)-i));
      }
    }
    cout<<res<<endl;
  }
  return 0;
}
