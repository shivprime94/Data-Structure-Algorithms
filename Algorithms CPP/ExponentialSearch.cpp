#include <bits/stdc++.h>
using namespace std;
 
int binarySearch(int arr[], int, int, int);

int exponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (i<n && arr[i]<=x)
        i=i*2;
    return binarySearch(arr, i/2,
                            min(i, n-1), x);
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r>=l)
    {
        int mid=l + (r - l)/2;
        if (arr[mid]==x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
 
    return -1;
}

int main(void)
{
   int n,x;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   cin>>x;
   int result = exponentialSearch(arr, n, x);
   if (result == -1)
   cout<<"Element is not present in array";
   else
   cout<<"Element is present at index "<<result;
   return 0;
}
 
