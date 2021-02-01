#include <bits/stdc++.h>
using namespace std;
vector<int> twosum(vector<int>& arr,int target){
  vector<int> ans;
  unordered_map<int,int> m;
  for(int i=0;i<arr.size();i++){
    if(m.find(target-arr[i]) != m.end()){
      ans.push_back(i);
      ans.push_back(m[target-arr[i]]);
      return ans;
    }
    else{
      m[arr[i]] = i;
    }
  }
  return ans;
}
int main(){
  vector<int> arr = {2,7,11,15};
  int target = 9;
  vector<int> ans = twosum(arr,target);
  for(auto i : ans){
    cout<<i<<" ";
  }
  return 0;
}
