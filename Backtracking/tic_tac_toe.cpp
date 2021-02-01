#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[3][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
    cout << arr[i][j] <<" ";
    cout << endl;
  }
}
int main(){
  #ifndef ONLINE_JUDGE
  freopen("F://C++//input.txt", "r", stdin);
  freopen("F://C++//output.txt", "w", stdout);
  #endif

  int arr[3][3];
  memset(arr,0,sizeof(arr));
  // solve(arr);
  return 0;
}
