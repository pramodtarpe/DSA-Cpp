#include<iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end){
  int len_a=mid-start+1;
  int len_b=end-mid;
  int A[len_a];
  int B[len_b];
  for(int i=0;i<len_a;i++) A[i]=arr[start+i];
  for(int j=0;j<len_b;j++) B[j]=arr[mid+1+j];

  int i=0;
  int j=0;
  int k=start;
  while (i < len_a && j < len_b)
   {
       if (A[i] <= B[j])
       {
           arr[k] = A[i];
           i++;
       }
       else
       {
           arr[k] = B[j];
           j++;
       }
       k++;
   }
   while (i < len_a)
   {
       arr[k] = A[i];
       i++;
       k++;
   }
   while (j < len_b)
   {
       arr[k] = B[j];
       j++;
       k++;
   }
}

void merge_sort(int arr[],int start,int end){
  if (start>=end) return;
  int mid = (start+end)/2;

  merge_sort(arr,start,mid);
  merge_sort(arr,mid+1,end);

  merge(arr,start,mid,end);
}

void printArray(int arr[],int size){
  for (int i=0;i<size;i++) cout<<arr[i]<<" ";
  cout<<endl;
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++) cin>>arr[i];
    merge_sort(arr,0,size-1);
    printArray(arr,size);

}
