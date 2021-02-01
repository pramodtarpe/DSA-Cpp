#include <bits/stdc++.h>
using namespace std;
bool isSafe(int **board, int row, int col){
  int i,j;
  int N = sizeof(board[0])/sizeof(board[0][0]);
  for(int i=0;i<row;i++)
    if(board[i][col])
      return false;

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
        return false;

  for (i = row, j = col; i >= 0 && j < N; i--, j++)
    if (board[i][j])
      return false;
  return true;
}
bool backtrack(int **board, int n,int row = 0){
  if(row >= n)
    return true;

  for(int col=0;col<n;col++){
    if(isSafe(board, row, col)){
      board[row][col] = 1;
      if(backtrack(board, n, row+1)){
        return true;
      }
      board[row][col] = 0;
    }
  }
  return false;
}
int main(){
  int n;
  cin >> n;
  int **board = new int*[n];
  for(int i=0;i<n;i++){
    board[i] = new int[n];
    for(int j=0;j<n;j++){
      board[i][j] = 0;
    }
  }
  if(backtrack(board,n)){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
      cout << board[i][j] <<" ";
      cout << endl;
    }
  }
  else{
    cout<<"False";
  }


  return 0;
}
