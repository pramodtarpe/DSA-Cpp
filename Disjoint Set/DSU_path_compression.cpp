#include <bits/stdc++.h>
using namespace std;
struct Graph{
  list<pair<int,int>> edges;
  int V;
  Graph(int V){
    this->V = V;
  }
  void addEdge(int e1,int e2){
    edges.push_back(make_pair(e1,e2));
  }
  int find(int e,int *parent){
    if(parent[e] == -1){
      return e;
    }
    return parent[e] = find(parent[e],parent);
  }
  void union_set(int x,int y,int *parent, int *rank){
    int s1 = find(x,parent);
    int s2 = find(y,parent);
    if(s1 != s2){
      if(rank[s1] < rank[s2]){
        parent[s1] = s2;
        rank[s2] += rank[s1];
      }
      else{
        parent[s2] = s1;
        rank[s1] += rank[s2];
      }
    }
  }
  bool isCycle(){
    int *parent = new int[V];
    int *rank= new int[V];
    for(int i=0;i<V;i++){
      parent[i] = -1;
      rank[i] = 1;
    }
    for(auto edge:edges){
      int e1 = edge.first;
      int e2 = edge.second;
      int s1 = find(e1,parent);
      int s2 = find(e2,parent);
      if(s1 != s2){
        union_set(s1,s2,parent,rank);
      }
      else{
        delete []parent;
        delete []rank;
        return true;
      }
    }
    delete []rank;
    delete []parent;
    return false;
  }
};

int main(){
#ifndef ONLINE_JUDGE
  freopen("F://C++//input.txt", "r", stdin);
  freopen("F://C++//output.txt", "w", stdout);
#endif
  cout<<boolalpha;
  int V,E;
  cin>>V>>E;
  Graph g(V);
  for(int i=0;i<E;i++){
    int e1,e2;
    cin>>e1>>e2;
    g.addEdge(e1,e2);
  }
  cout<<((g.isCycle())? "Cycle is Present":"Cycle is not Present");
  return 0;
}
