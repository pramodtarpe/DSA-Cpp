#include <bits/stdc++.h>
using namespace std;
void printArray(int **board, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout << board[i][j] <<" ";
		cout << endl;
	}
	cout<<"-----------------------------------------------------------------------"<<endl;
}
bool isSafe(int **board, int row, int col, int n){
  int i,j;
  for(int i=0;i<row;i++)
    if(board[i][col])
      return false;

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
        return false;

  for (i = row, j = col; i >= 0 && j < n; i--, j++)
    if (board[i][j])
      return false;
  return true;
}
void backtrack(int **board, int n,int row = 0){
  if(row >= n){
		printArray(board, n);
		return;
	}
  for(int col=0;col<n;col++){
    if(isSafe(board, row, col, n)){
      board[row][col] = 1;
    	backtrack(board, n, row+1);
			board[row][col] = 0;
		}
		continue;
  }
	return;
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
  backtrack(board,n);
}
  
