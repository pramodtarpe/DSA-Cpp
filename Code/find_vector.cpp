#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main(){
  FASTIO
  vector<int> vec {1,2,3,4,5};
 vector<int>:: iterator itr;
  itr = find(vec.begin(),vec.end(),22);
  if(itr != vec.end())
    cout<<"found";
  else
    cout<<"Not found";
  return 0;
}
