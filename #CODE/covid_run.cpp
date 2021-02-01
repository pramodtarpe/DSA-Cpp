#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main(){
  FASTIO
  int T;
  cin>>T;
  while(T--){
    bool infected = false;
    int cities,jump,current,live;
    cin>>cities>>jump>>current>>live;
    for(int i=0;i<cities;i++){
      if(live == current){
        infected = true;
        break;
      }
      current = (current+jump) % cities;
    }
    cout<<((infected)?"YES":"NO")<<endl;
  }
  return 0;
}
