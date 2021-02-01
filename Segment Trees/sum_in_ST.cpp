#include <bits/stdc++.h>
using namespace std;
void print(int arr[],int s,int e){
  for(int i=s;i<=e;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
void buildTree(int arr[],int tree[],int s,int e,int treenode){
  if(s == e){
    tree[treenode] = arr[s];
    return;
  }
  int mid = s+(e-s)/2;
  buildTree(arr,tree,s,mid,2*treenode);
  buildTree(arr,tree,mid+1,e,2*treenode+1);
  tree[treenode] = tree[2*treenode]+tree[2*treenode+1];
}
void update(int arr[],int tree[],int s,int e,int treenode,int idx,int value){
  if(s == e){
    arr[idx] = value;
    tree[treenode] = value;
    return;
  }
  int mid = s + (e-s)/2;
  if(idx <= mid){
    update(arr,tree,s,mid,2*treenode,idx,value);
  }
  else{
    update(arr,tree,mid+1,e,2*treenode+1,idx,value);
  }
  tree[treenode] = tree[2*treenode]+tree[2*treenode+1];
}
int query(int tree[],int s,int e,int treenode,int L,int R){
  if(R<s || L>e){
    return 0;
  }
  if(L<=s && R>=e){
    return tree[treenode];
  }
  int mid = s + (e-s)/2;
  return query(tree,s,mid,2*treenode,L,R) + query(tree,mid+1,e,2*treenode+1,L,R);
}
int main(){
  #ifndef ONLINE_JUDGE
    freopen("F://C++//input.txt", "r", stdin);
    freopen("F://C++//output.txt", "w", stdout);
  #endif
  int n;
  cin>>n;
  int arr[n],tree[10];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  print(arr,0,n-1);
  memset(tree,-1,sizeof(tree));
  buildTree(arr,tree,0,n-1,1);
  print(tree,1,9);
  cout<<"sum :"<<query(tree,0,n-1,1,1,3)<<endl;
  update(arr,tree,0,n-1,1,0,5);
  print(tree,1,9);
  return 0;
}
