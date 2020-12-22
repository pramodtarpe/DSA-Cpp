#include <bits/stdc++.h>
#include <climits>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main(){
  FASTIO
  int T;
  cin>>T;
  while(T--){
    int n;
    int ans=0;
    cin>>n;
    int next;
    int prev=INT_MAX;

    while(n--){
      cin>>next;
      if(next<=prev){
        ans++;
        prev=next;
      }
    }
    // int arr[n];
    // int ans=1;
    // for(int i=0;i<n;i++) cin>>arr[i];
    // if(n==1){
    //   cout<<ans<<endl;
    //   continue;
    // }
    // for(int i=1;i<n;i++){
    //   if(arr[i]<=arr[i-1]){
    //     ans++;
    //   }
    //   else{
    //     arr[i]=arr[i-1];
    //   }
    // }
    cout<<ans<<endl;
  }
  return 0;
}
