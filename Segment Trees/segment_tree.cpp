#include <bits/stdc++.h>
using namespace std;
void buildTree(int arr[],int s,int e,int tree[],int index){
  if(s == e){
    tree[index] = arr[s];
    return;
  }
  int mid = s+(e-s)/2;
  buildTree(arr,s,mid,tree,2*index);
  buildTree(arr,mid+1,e,tree,2*index+1);
  tree[index] = min(tree[2*index], tree[2*index+1]);
}
int main(){
  #ifndef ONLINE_JUDGE
    freopen("F://C++//input.txt", "r", stdin);
    freopen("F://C++//output.txt", "w", stdout);
  #endif

  int n;
  cin>>n;
  int arr[n],tree[4*n + 1];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  memset(tree,-1,sizeof(tree));
  buildTree(arr,0,n-1,tree,1);
  for(int i=1;i<(4*n+1);i++){
    cout<<tree[i]<<" ";
  }
  return 0;
}
