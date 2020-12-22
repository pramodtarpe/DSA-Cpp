#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main(){
  FASTIO
  int n;
  cin>>n;

  for(int i=1;i<=n;i++){
    for(int space=1 ;space<=n+1-i ;space++){
      cout<<" ";
    }
    for(int j=1;j<=i;j++){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}
