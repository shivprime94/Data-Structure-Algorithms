

/*
PROBLEM :
Given an array arr[] of N non-negative integers representing the height of blocks.
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
*/

//CODE : 
#include <bits/stdc++.h>
using namespace std;

class Solution{
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int  lmax[n], rmax[n];

        // To store the maximum water that can be stored
        long long int res=0;

        lmax[0]=arr[0], rmax[n-1]=arr[n-1];
        //Find the maximum element on its left
        for(int j=1;j<n;j++)
           lmax[j]= max(arr[j],lmax[j-1]);

        //Find the maximum element on its right
        for(int j=n-2;j>-1;j--)
           rmax[j]= max(arr[j],rmax[j+1]);

         // Update the maximum water
        for( int i=0;i<n;i++)
            res+=min(lmax[i],rmax[i])-arr[i];


            return res;
    }
};


int main()
{


        int n;
        cin>>n;
        int A[n];
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.trappingWater(A, n);

    return 0;
}

/*
//EXAMPLE 1 :
Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units
*/

/*
//EXAMPLE 2 : 
Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.
*/
