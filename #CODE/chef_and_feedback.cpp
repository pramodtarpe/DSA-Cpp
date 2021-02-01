#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main(){
  FASTIO
  int T;
  cin>>T;
  while(T--){
    string str;
    cin >> str;
    if(str.size()<=2){
      cout<<"Bad"<<endl;
      continue;
    }
      int p=0;
      int curr=1;
      int forward=2;
      bool flag = false;
      while(forward != str.size()){
        if(str[p] == str[forward] && str[p] != str[curr]) {
          flag = true;
          break;
        }
        else{
          p++;
          curr++;
          forward++;
        }
      }
      if(flag){
        cout<<"Good"<<endl;
      }
      else{
        cout<<"Bad"<<endl;
      }
  }
  return 0;
}
