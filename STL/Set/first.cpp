#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main(){
  FASTIO
  set<int> s;
  int arr[] {99,1,2,3,1,2,3,4,5,6,1,4,5,5,5};
  int size = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<size;i++){
    s.insert(arr[i]);
  }

  for(auto i :s){
    cout<<i<<" ";
  }
  return 0;
}
