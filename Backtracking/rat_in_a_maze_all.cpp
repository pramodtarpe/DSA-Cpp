#include <bits/stdc++.h>
using namespace std;
bool isSafe(int **maze,int x, int y, int n){
  return ((x < n) && (y < n))? maze[x][y]: false;
}
void printArray(int **ansMaze,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    cout << ansMaze[i][j] <<" ";
    cout << endl;
  }
  cout<<"-----------------------------------------------------------------------"<<endl;
}
int backtrack(int **maze,int x, int y, int n, int **ansMaze){
  static int possible = 0;
  if((x == n-1) && (y == n-1)){
    ansMaze[x][y] = 1;
    printArray(ansMaze, n);
    possible++;
    return possible;
  }
  if(isSafe(maze,x,y,n)){
    ansMaze[x][y] = 1;
    backtrack(maze,x+1,y,n,ansMaze);
    backtrack(maze,x,y+1,n,ansMaze);
    ansMaze[x][y] = 0;
  }
  return possible;
}

int main(){
  int n;
  cin >>n;
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
  cout<<endl;
  cout<<backtrack(maze,0,0,n,ansMaze)<<endl;
  return 0;
}
