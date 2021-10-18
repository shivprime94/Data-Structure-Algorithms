// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
  
  //Solution part
    vector<int> subarraySum(int a[], int n, int s)
    {
        // Your code here
        int i=0,j=0,sum=0;
        vector<int> ans;
        while(j<n&&sum+a[j]<=s)
            sum+=a[j++];
        
         if(sum==s){
                ans.push_back(i+1);
                ans.push_back(j);
                return ans;
         }
        while(j<n){
            sum+=a[j];
            while(sum>s){
                sum-=a[i];
                i++;
            }
            if(sum==s){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
                
            }
            j++;
        }
        ans.push_back(-1);
        return ans;
    }
  //Solution ends here
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
