class Solution {
public:
    int arrange(int i, int j, int n, vector<int>& dp){
        // base case
        if(i > j) return 1;
        if(i == j) return 1;

        // dp check
        if(dp[j-i+1]!=-1) return dp[j-i+1];

        // approach: arrange(i, j, n, dp) --> function which returns no. of bst from [i...j]
        // we iterate through the entire [i...j] and take each element as root and generate no. of
        // possibilities for its left and right subtrees.
        
        // Note: 1D DP optimized version

        int ans = 0;
        for(int k=i; k<=j; k++){
            ans += arrange(i, k-1, n, dp) * arrange(k+1, j, n, dp);
        }
        return dp[j-i+1] = ans;
    }
    int numTrees(int n) {
        // memoization:
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // we can further optimize it to 1D DP, as i and j need not to be unique, since we are not given
        // an array, only the no. of elements b/w i and j matters to us.
        vector<int> dp(n+1, -1);
        return arrange(0, n-1, n, dp);
    }
};
