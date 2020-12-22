#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main(){
  FASTIO
  int n=5;

  for(int i=1;i<=5;i++){
    int star = i;
    for(int j=1;j<=i;j++){
      cout<<(star)%2<<" ";
      star++;
    }
    cout<<endl;
  }
  return 0;
}
