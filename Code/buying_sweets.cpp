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
    int size,sweet;
    cin>>size>>sweet;
    int arr[size];
    int total=0;
    for(int i=0;i<size;i++) {
      cin>>arr[i];
      total += arr[i];
    }
    int rem = total%sweet;
    int quo = total/sweet;
    sort(arr,arr+size);

    if(rem>=arr[0]) cout<<-1<<endl;
    else cout<<quo<<endl;
  }
  return 0;
}
