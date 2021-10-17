//@soumyaagr427

#include <bits/stdc++.h>
using namespace std;


class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       
        deque<int> d;
        vector<int> ans;
        
        for(int i=0;i<k;i++){
            while(!d.empty() and arr[d.back()]<arr[i])
                d.pop_back();
        
            d.push_back(i);
        }
        ans.push_back(arr[d.front()]);
        
        for(int i=k;i<n;i++){
            if(d.front()==i-k)
                d.pop_front();
            
            while(!d.empty() and arr[d.back()]<arr[i])
                d.pop_back();
        
            d.push_back(i);
            ans.push_back(arr[d.front()]);
        }
        
        return ans;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  
