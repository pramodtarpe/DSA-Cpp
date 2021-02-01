#include <bits/stdc++.h>
using namespace std;
int lazy[10000] = {0};
void buildTree(int arr[],int tree[],int start,int end,int index){
  if(start == end){
    tree[index] = arr[start];
    return;
  }
  int mid = start + (end-start)/2;
  buildTree(arr,tree,start,mid,2*index);
  buildTree(arr,tree,mid+1,end,2*index+1);
  tree[index] = min(tree[2*index], tree[2*index+1]);
}
void updateLazy(int tree[],int start,int end,int L,int R,int inc,int index){
  if(lazy[index] != 0){
    tree[index] += lazy[index];
    if(start != end){
      lazy[2*index] += lazy[index];
      lazy[2*index+1] += lazy[index];
    }
    lazy[index] = 0;
  }
  if(L > end || R < start){
    return;
  }
  if(start >= L && end <= R){
    tree[index] += inc;
    if(start != end){
      lazy[2*index] += inc;
      lazy[2*index+1] += inc;
    }
    return;
  }
  int mid = start + (end-start)/2;
  updateLazy(tree,start,mid,L,R,inc,2*index);
  updateLazy(tree,mid+1,end,L,R,inc,2*index+1);
  tree[index] = min(tree[2*index],tree[2*index+1]);
}
int queryLazy(int tree[],int start,int end,int L,int R,int index){
  if(lazy[index] != 0){
    tree[index] += lazy[index];
    if(start != end){
      lazy[2*index] += lazy[index];
      lazy[2*index+1] += lazy[index];
    }
    lazy[index] = 0;
  }
  if(L > end || R < start){
    return INT_MAX;
  }
  if(L<=start && R>=end){
    return tree[index];
  }
  int mid = start + (end-start)/2;
  return min(queryLazy(tree,start,mid,L,R,2*index),queryLazy(tree,mid+1,end,L,R,2*index+1));
}
int main(){
  #ifndef ONLINE_JUDGE
    freopen("F://C++//input.txt", "r", stdin);
    freopen("F://C++//output.txt", "w", stdout);
  #endif
  int n;
  cin>>n;
  int arr[n] = {0},tree[4*n+1];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  buildTree(arr,tree,0,n-1,1);
  updateLazy(tree,0,n-1,0,5,-100,1);
  for(int i=1;i<14;i++){
    cout<<tree[i]<<" ";
  }
  cout<<endl;
  cout<<queryLazy(tree,0,n-1,2,3,1)<<endl;
  return 0;
}
