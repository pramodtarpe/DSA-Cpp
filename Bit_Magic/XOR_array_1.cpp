#include <bits/stdc++.h>
using namespace std;
//finding odd occuring element
int main(){
  int arr[]{1,1,2,3,2,3,5};
  int ans = 0;
  for(int i=0;i<7;i++){
    ans = ans^arr[i];
  }
  cout << ans;
}
