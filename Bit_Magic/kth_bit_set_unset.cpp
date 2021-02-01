#include <bits/stdc++.h>
using namespace std;

int main(){
  cout<<boolalpha;
  unsigned int n;
  int k;
  cin>>n>>k;
  unsigned int a = (1<<k);
  cout<< bool(n&a);
  return 0;
}
