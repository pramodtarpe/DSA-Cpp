// Arrange numbers 1-9 in a 3x3 matrix such that we get sum 15 by adding
// nums from any direction
#include <bits/stdc++.h>
using namespace std;
int counter = 0;
void printArray(int arr[3][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
    cout << arr[i][j] <<" ";
    cout << endl;
  }
}
bool findEmpty(int arr[3][3], int &x, int &y){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
      if(arr[i][j] == 0){
        x = i;
        y = j;
        return true;
      }
  }
  return false;
}
bool isSafe(int arr[3][3], int row, int col, int num){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
      if(arr[i][j] == num){
        return false;
      }
  }
  return true;
}
bool correct(int arr[3][3]){
  int r1,r2,r3,c1,c2,c3,d1,d2;
  r1 = arr[0][0] + arr[0][1] + arr[0][2];
  r2 = arr[1][0] + arr[1][1] + arr[1][2];
  r3 = arr[2][0] + arr[2][1] + arr[2][2];
  c1 = arr[0][0] + arr[1][0] + arr[2][0];
  c2 = arr[0][1] + arr[1][1] + arr[2][1];
  c3 = arr[0][2] + arr[1][2] + arr[2][2];
  d1 = arr[0][0] + arr[1][1] + arr[2][2];
  d2 = arr[0][2] + arr[1][1] + arr[2][0];
  if(r1==r2 && r2==r3 && r3==c1 && c1==c2 && c2==c3 && c3==d1 && d1==d2 && d2==r1)
    return true;
  return false;
}
void solve(int arr[3][3]){
  int row,col;
  if(!findEmpty(arr,row,col)){
    if (correct(arr)){
      printArray(arr);
      cout<<"---------------------------------------"<<endl;
      counter++;
      return;
    }
    else{
      arr[2][2] = 0;
      return;
    }
  }
  for(int num = 1;num<=9;num++){
    if(isSafe(arr,row,col,num)){
      arr[row][col] = num;
      solve(arr);
      arr[row][col] = 0;
    }
  }
  return;
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("F://C++//input.txt", "r", stdin);
  freopen("F://C++//output.txt", "w", stdout);
  #endif

  int arr[3][3];
  memset(arr,0,sizeof(arr));
  solve(arr);
  cout<<counter<<endl;
  return 0;
}
