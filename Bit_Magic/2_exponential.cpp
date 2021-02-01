#include <bits/stdc++.h>
using namespace std;

int main(){
  cout<<boolalpha;
  unsigned int a;
  cin>>a;
  cout<< (!(a&(a-1)) && a!=0)? true:false;
  cout<<endl;

  return 0;
}
