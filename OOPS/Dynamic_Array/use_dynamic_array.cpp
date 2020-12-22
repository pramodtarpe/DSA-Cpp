#include<bits/stdc++.h>
#include "DynamicArray.h"
using namespace std;

int main(){
  DynamicArray<pair<int,int>> arr;

  // for(int i = 1;i<=10;i++)
  // arr.insert(i);
  // arr.display();
  // cout<<"size: "<<arr.getSize()<<endl;
  // cout<<"capacity: "<<arr.getCapacity()<<endl;
  // cout<<"-----------------------------------------"<<endl;
  // for(int i = 1;i<=5;i++)
  // cout<< arr.remove() <<" ";
  // cout<<endl;
  // cout<<"size: "<<arr.getSize()<<endl;
  // cout<<"capacity: "<<arr.getCapacity()<<endl;
  // cout<<"-----------------------------------------"<<endl;
  // arr.display();
  // cout<<"size: "<<arr.getSize()<<endl;
  // cout<<"capacity: "<<arr.getCapacity()<<endl;
  // cout<<"-----------------------------------------"<<endl;
  for(int i=1;i<=10;i++){
    pair<int,int> p(i,i*i);
    arr.insert(p);
  }
  for(int i=0;i<10;i++){
    cout<< arr.array[i].first << " " << arr.array[i].second <<endl ;
  }

}
