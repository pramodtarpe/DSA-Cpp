// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return true;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return false;
}

int main(void)
{
    int arr[] {1,2,3,4,5,6,7,8,9,10};
    int x = 19;
    int n = sizeof(arr) / sizeof(arr[0]);
    bool result = binarySearch(arr, 0, n - 1, x);
    cout<<boolalpha<<endl;
    cout<<result<<endl;
    return 0;
}
