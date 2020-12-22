#include <bits/stdc++.h>
#define FASTIO     ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
void printKMax(int arr[], int n, int k){
    int __max = 0;
    for(int i=0;i<n;i++){
      __max = max(__max, arr[i]);
      if(i%2==1){
        cout<<__max<<" ";
        __max=0;
      }
    }
    cout<<endl;
}
int main(){
  FASTIO
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
