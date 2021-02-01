#include <bits/stdc++.h>
using namespace std;
//finding odd 2 occuring element
bool setBit(int n, int pos){
  return (n &(1<<pos) != 0);
}

int main(){
  int arr[]{1,1,2,3,2,3,5,9};
  int XOR = arr[0];
  for(int i=1;i<8;i++){
    XOR = XOR^arr[i];
  }
  cout<<XOR<<endl;
  int pos = 0;
  int setbit = 0;
  while(setbit&1 != 1){
    setbit = XOR&1;
    pos++;
    XOR = XOR>>1;
  }

  int newxor = 0;
  for(int i=0;i<8;i++){
    if (setBit(arr[i], pos)){
      newxor = newxor^arr[i];
    }
  }
  cout <<newxor;
}
