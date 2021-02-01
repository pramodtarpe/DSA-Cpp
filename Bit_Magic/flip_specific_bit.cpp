// XOR with 1
#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned int num;
  unsigned int k;
  cin >> num >> k;
  k = (1<<k);
  cout<<(num^k)<<endl;
  return 0;
}
