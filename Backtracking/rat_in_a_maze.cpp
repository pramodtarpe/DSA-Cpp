#include <bits/stdc++.h>
using namespace std;
bool isSafe(int **maze,int x, int y, int n){
  return ((x < n) && (y < n))? maze[x][y]: false;
}
bool backtrack(int **maze,int x, int y, int n, int **ansMaze){
  if((x == n-1) && (y == n-1)){
    ansMaze[x][y] = 1;
    return true;
  }
  if(isSafe(maze,x,y,n)){
    ansMaze[x][y] = 1;
    if(backtrack(maze,x+1,y,n,ansMaze)){
      return true;
    }
    if(backtrack(maze,x,y+1,n,ansMaze)){
      return true;
    }
    ansMaze[x][y] = 0;
    return false;
  }
  return false;
}

int main(){
  cout << boolalpha;
  int n;
  cin >> n;
  int **maze = new int*[n];
  int **ansMaze = new int*[n];
  for(int i=0;i<n;i++){
    maze[i] = new int[n];
    ansMaze[i] = new int[n];
    for(int j=0;j<n;j++){
      ansMaze[i][j] = 0;
      cin>>maze[i][j];
    }
  }
  cout<<backtrack(maze,0,0,n,ansMaze) << endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout << ansMaze[i][j] <<" ";
    cout << endl;
  }
  return 0;
}
