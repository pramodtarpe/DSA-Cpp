#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long int ull;
using namespace std;

int main(){
  FASTIO
  ull T;
  cin>>T;
  while(T--){
    ull size;
    cin>>size;
    string str;
    cin>>str;
    ull ans=0;
    for (ull i=0;i<size;i++){
      if(str[i] == '1') ans++;
    }
    //

    ans += (ans*(ans+1)/2) - ans;
    //
    cout<<ans<<endl;
  }
  return 0;
}
