#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main(){
  FASTIO
  int T;
  cin>>T;
  while(T--){
    int n,k;
    cin>>n>>k;
    int __and;
    int __max=0;
    for (int i=1;i<=n-1;i++){
      for(int j=i+1;j<=n;j++){
        __and = i&j;
        if(__and < k)
          __max = max(__max,__and);
      }
    }
    cout<<__max<<endl;
  }
  return 0;
}
