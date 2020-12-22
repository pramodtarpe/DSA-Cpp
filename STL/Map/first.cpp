#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main(){
  FASTIO
  map<int,int> m;
  int arr[] {1,2,3,1,2,3,4,5,6,1,4,5,5,5};
  map<int,int>::iterator itr;
  int size = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<size;i++){
    m[arr[i]] += 1;
  }
  //print map
  for(itr = m.begin();itr!=m.end();itr++){
    cout<< itr->first<<" : "<<itr->second
    <<endl;
  }
  return 0;
}
