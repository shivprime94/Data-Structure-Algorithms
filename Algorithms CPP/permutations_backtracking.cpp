// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:

	    void permute(string s, int i, vector<string> &ans){
	        if(i == s.length()){
	            ans.push_back(s);
	            return;
	        }

	        for(int j = i; j < s.length(); j++){
	            swap(s[i], s[j]);
	            permute(s, i + 1, ans);
              // backtracking
	            swap(s[i], s[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    permute(S, 0, ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
