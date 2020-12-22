#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;
#define range(n) for(int i=0;i<n;i++)
#define in(n,arr) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr) for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++) cout<<arr[i]<<" ";cout<<endl;
#define all(V) for(auto i=V.begin();i != V.end(); i++) cout<<*i<<" ";cout<<endl;

using namespace std;

int main(){
  FASTIO
  int T;
  cin>>T;
  int arr[6];
  int count = 0;
  while(T--){
    in(6,arr);
    int d1 = (((arr[2]-arr[0])*(arr[2]-arr[0])) + ((arr[3]-arr[1])*(arr[3]-arr[1]))) ;
    int d2 = (((arr[4]-arr[0])*(arr[4]-arr[0])) + ((arr[5]-arr[1])*(arr[5]-arr[1]))) ;
    int d3 = (((arr[4]-arr[2])*(arr[4]-arr[2])) + ((arr[5]-arr[3])*(arr[5]-arr[3]))) ;
    int ans[]{d1,d2,d3};
    sort(ans,ans+3);
    if(ans[2] == ans[0]+ans[1])
      count++;
  }
  cout<<count<<endl;
  return 0;
}
