#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned int a,i;
  unsigned int A,B,M;
  cin >> a >> i;
  A = (1<<(i+1));
  B = A-1;
  M = ~B;
  cout << (a&M)<<endl;
  return 0;
}
