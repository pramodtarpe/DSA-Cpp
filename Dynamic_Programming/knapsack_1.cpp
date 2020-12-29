#include <bits/stdc++.h>
using namespace std;
int knapsack(int weight[], int value[],int N, int W){
  if(N == 0 || weight <= 0){
    return 0;
  }
  int c1 = 0, c2 = 0;
  if(W-weight[0] >= 0){
    c1 = value[0] + knapsack(weight+1,value+1,N-1,W-weight[0]);
  }
  c2 = knapsack(weight+1,value+1,N-1,W);
  return max(c1,c2);
}
int main(){
  int N = 10;
  int value[]{1,2,3,4,5,6,7,8,9,0};
  int weight[]{1,2,3,4,5,6,7,8,9,0};
  int W = 0;
  cout<< knapsack(weight,value,N,W);
  return 0;
}
