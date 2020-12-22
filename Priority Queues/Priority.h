#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
public:
  vector<int> pq;
  bool isEmpty(){
    return pq.size()==0;
  }
  int getSize(){
    return pq.size();
  }
  int getMin(){
    if (!pq.size())
    return pq[0];
    return 0;
  }

  void insert(int element){
    pq.push_back(element);
    int childIndex = pq.size()-1;
    int ParentIndex = (childIndex-1)/2;
    while(childIndex > 0 && (pq[childIndex] < pq[ParentIndex]) ){
      swap(pq[childIndex], pq[ParentIndex]);
      childIndex = ParentIndex;
      ParentIndex = (childIndex-1)/2;
    }
  }

  int removeMin(){
    if(pq.empty()){
      return 0;
    }
    int ans = pq[0];
    swap(pq[0], pq[pq.size()-1]);
    pq.pop_back();
    int ParentIndex = 0;
    int minIndex = -1;
    int LCI = (2*ParentIndex )+ 1;
    int RCI = (2*ParentIndex )+ 2;
    while(LCI < pq.size()){
      if(RCI < pq.size()){
        minIndex = (pq[LCI] < pq[RCI])? LCI:RCI;
      }
      else{
        minIndex = LCI;
      }
      if(pq[ParentIndex] > pq[minIndex]){
        swap(pq[ParentIndex], pq[minIndex]);
        ParentIndex = minIndex;
        LCI = (2*ParentIndex )+ 1;
        RCI = (2*ParentIndex )+ 2;
      }else break;
    }
    return ans;
  }



};
