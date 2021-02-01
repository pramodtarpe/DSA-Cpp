#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A){
  unordered_map<int,int> m;
  int start = 0;
  int lastindex = A.size()-1;
  int begin = -1,end = -1;
  for(int i=start;i<=lastindex;i++){
    m[A[i]]++;
    if(m[A[i]] >= 3){
      begin = i;
      while(lastindex > begin){
        m[A[lastindex]]++;
        if(m[A[lastindex]] >= 3){
          end = lastindex;
          // cout<<begin<<" "<<end<<endl;
          return (end-begin+1);
        }
        lastindex--;
      }
      return 1;
    }
  }
  return 0;
}
int main(){
  #ifndef ONLINE_JUDGE
    freopen("F://C++//input.txt", "r", stdin);
    freopen("F://C++//output.txt", "w", stdout);
  #endif
  vector<int> v;
  stringstream ss;
  string str;
  getline(cin,str);
  ss<<str;
  int a;
  while(ss >> a){
    v.push_back(a);
  }
  cout<<solve(v);
  return 0;
}
