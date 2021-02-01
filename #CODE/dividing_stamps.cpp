#include <iostream>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;
#define range(n) for(int i=0;i<n;i++)
#define in(n,arr) for(int i=0;i<n;i++) cin>>arr[i];
#define out(n,arr) for(int i=0;i<n;i++) cout<<arr[i]<<" ";cout<<endl;
#define all(V) for(auto i=V.begin();i != V.end(); i++) cout<<*i<<" ";cout<<endl;

using namespace std;
ll sumn(ll n){
  return (n*(n+1))/2 ;
}
int main(){
  FASTIO
  ll n;
  cin>>n;
  ll total=0;
  range(n){
    ll Ci;
    cin>>Ci;
    total+=Ci;
  }
  if(sumn(n) == total){
    cout<<"YES"<<endl;
  }
  else cout<<"NO"<<endl;
  return 0;
}
