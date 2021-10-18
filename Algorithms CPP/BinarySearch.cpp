#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}
int main()
{

   int l,r,x;
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];

   cout<<"Enter the element to be found ";
   cin>>x;

   int ans=binarySearch(a,0,n-1,x);
   if(ans==-1)
   cout<<"Element is not found ";
   else
   cout<<"Element is found at "<<ans<<" position ";

  return 0;
 }
