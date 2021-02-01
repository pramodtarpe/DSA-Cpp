#include <bits/stdc++.h>
using namespace std;
struct node{
  int maximum,pairsum;
};
void buildTree(int arr[],node tree[],int start,int end,int index){
  if(start == end){
    tree[index].maximum = arr[start];
    tree[index].pairsum = 0;
    return;
  }
  int mid = start+(end-start)/2;
  buildTree(arr,tree,start,mid,2*index);
  buildTree(arr,tree,mid+1,end,2*index+1);
  tree[index].maximum = max(tree[2*index].maximum,tree[2*index+1].maximum);
  tree[index].pairsum = max(tree[2*index].pairsum,max(tree[2*index+1].pairsum,tree[2*index].maximum+tree[2*index+1].maximum));
}
void update(int arr[],node tree[],int start,int end,int index,int idx,int value){
  if(start == end){
    arr[idx] = value;
    tree[index].maximum = value;
    return;
  }
  int mid = start+(end-start)/2;
  if(idx <= mid){
    update(arr,tree,start,mid,2*index,idx,value);
  }
  else{
    update(arr,tree,mid+1,end,2*index+1,idx,value);
  }
  tree[index].maximum = max(tree[2*index].maximum,tree[2*index+1].maximum);
  tree[index].pairsum = max(tree[2*index].pairsum,max(tree[2*index+1].pairsum,tree[2*index].maximum+tree[2*index+1].maximum));
}
node* query(node tree[],int start,int end,int index,int L,int R){
  if(R<start || L>end){
    node *temp = new node;
    temp->maximum = 0;
    temp->pairsum = 0;
    return temp;
  }
  if(L<=start && R>=end){
    node *test = new node;
    test->maximum = tree[index].maximum;
    test->pairsum = tree[index].pairsum;
    return test;
  }
  int mid = start+(end-start)/2;
  node *n1 = query(tree,start,mid,2*index,L,R);
  node *n2 = query(tree,mid+1,end,2*index+1,L,R);
  node *ans = new node;
  ans->maximum = max(n1->maximum,n2->maximum);
  ans->pairsum = max(n1->pairsum,max(n2->pairsum,n1->maximum+n2->maximum));
  return ans;
}
int main(){
  #ifndef ONLINE_JUDGE
    freopen("F://C++//input.txt", "r", stdin);
    freopen("F://C++//output.txt", "w", stdout);
  #endif
  int n;
  cin>>n;
  int arr[n];
  node tree[4*n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  buildTree(arr,tree,0,n-1,1);
  // update(arr,tree,0,n-1,1,0,100);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  for(int i=1;i<13;i++){
    cout<<tree[i].maximum<<" ";
  }
  cout<<endl;
  for(int i=1;i<15;i++){
    cout<<tree[i].pairsum<<" ";
  }
  cout<<endl;
  cout<<"Query: "<<(query(tree,0,n-1,1,2,3))->pairsum;
  return 0;
}
