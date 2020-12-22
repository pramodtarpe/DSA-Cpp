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
    for(int j=i;j<=n+(n-1);j++){
      if(j<=n-1)
        cout<<" ";
      else
        cout<<"* ";
    }
    cout<<endl;
  }
  return 0;
}
