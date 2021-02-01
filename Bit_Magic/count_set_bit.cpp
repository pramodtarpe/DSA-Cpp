// Brian Karnighans Algorithm
#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned long long int n;
  int ans = 0;
  cin>>n;
  while(n>0){
    n = n&(n-1) ;
    ans++;
  }
  cout<<ans;
  return 0;
}
