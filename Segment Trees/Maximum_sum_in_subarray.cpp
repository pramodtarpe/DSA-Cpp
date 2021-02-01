#include <bits/stdc++.h>
using namespace std;
struct node{
  long long sum = 0;
  long long maxsum = 0;
  long long prefix = 0;
  long long suffix = 0;
};
void buildTree(int arr[],node tree[],int start,int end,int index){
  if(start == end){
    tree[index].sum = arr[start];
    tree[index].maxsum = arr[start];
    tree[index].prefix = arr[start];
    tree[index].suffix = arr[start];
    return;
  }
  int mid = (start + (end - start)/2);
  buildTree(arr,tree,start,mid,2*index);
  buildTree(arr,tree,mid+1,end,2*index+1);
  const node *LC = &tree[2*index];
  const node *RC = &tree[2*index+1];
  tree[index].sum = (LC->sum + RC->sum);
  long long a = max(LC->maxsum,RC->maxsum);
  long long b = max(LC->sum+RC->prefix,RC->sum+LC->suffix);
  tree[index].maxsum = max(a,max(b,(LC->suffix+RC->prefix)));
  tree[index].prefix = max(LC->prefix,LC->sum+RC->prefix);
  tree[index].suffix = max(RC->suffix,RC->sum+LC->suffix);
}
void update(int arr[],node tree[],int start,int end,int index,int idx,int value){
  if(idx<start || idx>end){
    return;
  }
  if(start == end){
    arr[start] = value;
    tree[index].sum = arr[start];
    tree[index].maxsum = arr[start];
    tree[index].prefix = arr[start];
    tree[index].suffix = arr[start];
    return;
  }
  int mid = start + (end-start)/2;
  update(arr,tree,start,mid,2*index,idx,value);
  update(arr,tree,mid+1,end,2*index+1,idx,value);
  const node *LC = &tree[2*index];
  const node *RC = &tree[2*index+1];
  tree[index].sum = (LC->sum + RC->sum);
  long long a = max(LC->maxsum,RC->maxsum);
  long long b = max(LC->sum+RC->prefix,RC->sum+LC->suffix);
  tree[index].maxsum = max(a,max(b,(LC->suffix+RC->prefix)));
  tree[index].prefix = max(LC->prefix,LC->sum+RC->prefix);
  tree[index].suffix = max(RC->suffix,RC->sum+LC->suffix);
}
node query(node tree[],int start,int end,int index,int L,int R){
  if(R<start || L>end){
    node temp;
    temp.sum = INT_MIN;
    temp.maxsum = INT_MIN;
    temp.prefix = INT_MIN;
    temp.suffix = INT_MIN;
    return temp;
  }
  if(L<=start && R>=end){
    node temp;
    temp.sum = tree[index].sum;
    temp.maxsum = tree[index].maxsum;
    temp.prefix = tree[index].prefix;
    temp.suffix = tree[index].suffix;
    return temp;
  }
  int mid = start+(end-start)/2;
  node LC = query(tree,start,mid,2*index,L,R);
  node RC = query(tree,mid+1,end,2*index+1,L,R);
  node ans;
  ans.sum = (LC.sum + RC.sum);
  long long a = max(LC.maxsum,RC.maxsum);
  long long b = max(LC.sum+RC.prefix,RC.sum+LC.suffix);
  ans.maxsum = max(a,max(b,(LC.suffix+RC.prefix)));
  ans.prefix = max(LC.prefix,LC.sum+RC.prefix);
  ans.suffix = max(RC.suffix,RC.sum+LC.suffix);
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
  node tree[4*n+1];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  buildTree(arr,tree,0,n-1,1);
  update(arr,tree,0,n-1,1,0,1);
  update(arr,tree,0,n-1,1,1,2);
  update(arr,tree,0,n-1,1,2,-3);
  update(arr,tree,0,n-1,1,3,4);
  update(arr,tree,0,n-1,1,4,5);
  update(arr,tree,0,n-1,1,5,6);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  for(int i=1;i<=13;i++){
    cout<<tree[i].maxsum<<" ";
  }
  cout<<endl;
  cout<<"Query: "<<(query(tree,0,n-1,1,2,3)).maxsum<<endl;
  cout<<"Query: "<<(query(tree,0,n-1,1,1,4)).maxsum<<endl;
  return 0;
}
