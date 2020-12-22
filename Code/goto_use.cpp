#include <bits/stdc++.h>
using namespace std;

int main(){
  int a = 0;
  long long sum=0;
  while(true){
    cin >>a;
    if(a == -1){
      goto hell;
    }
    sum += a;
  }
  hell:
    cout<<sum<<endl;

  return 0;
}
