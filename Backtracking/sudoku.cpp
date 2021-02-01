#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[9][9],int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    cout << arr[i][j];
    cout << endl;
  }
}
bool isSafe(int board[9][9], int row, int col,int num){
  int i,j;
  for(i=0;i<9;i++){
    if(board[i][col] == num){
      return false;
    }
  }
  for(j=0;j<9;j++){
    if(board[row][j] == num){
      return false;
    }
  }
  int rowF = row - (row%3);
  int colF = col - (col%3);

  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(board[i+rowF][j+colF] == num)
      return false;
    }
  }
  return true;
}
bool findEmpty(int board[9][9], int &row, int &col){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(board[i][j] == 0){
        row = i;
        col = j;
        return true;
      }
    }
  }
  return false;
}
bool backtrack(int board[9][9]){
  int row,col;
  if(!findEmpty(board,row,col)){
    return true;
  }
  else{
    for(int num = 1;num<=9;num++){
      if(isSafe(board,row,col,num)){
        board[row][col] = num;
        if(backtrack(board)){
          return true;
        }
        board[row][col] = 0;
      }
    }
  }
  return false;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("F://C++//input.txt", "r", stdin);
    freopen("F://C++//output.txt", "w", stdout);
  #endif

  int board[9][9];

  char input[10];
  for(int i=0;i<9;i++){
    cin >> input;
    for(int j=0;j<9;j++){
      board[i][j] = int(input[j]-48);
    }
  }
  backtrack(board);
  printArray(board, 9);
  return 0;
}
