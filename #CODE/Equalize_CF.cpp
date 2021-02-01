#include <bits/stdc++.h>
using namespace std;

int main(){
  int size=0, cost=0, i=0;
  string a,b;
  cin>>size;
  cin>>a;
  cin>>b;
  while(i < size){
    if(b[i] != a[i]){
      if((i<size-1) && (b[i+1] == a[i]) && (b[i] == a[i+1])){
        swap(b[i], b[i+1]);
        cost++;
        i+=2;
      }
      else{
        b[i] = a[i];
        cost++;
        i++;
      }
    }
    else{
      i++;
    }
  }
  cout<<cost<<endl;
  return 0;
}
