class Solution
{
public:
    int helper(vector<int> &a, int si, vector<int> &dp)
    {
        // top-down approach
        if (si >= a.size())
            return 0;

        if (dp[si] != -1)
            return dp[si];
        int include = a[si] + helper(a, si + 2, dp);
        int exclude = helper(a, si + 1, dp);
        dp[si] = max(include, exclude);

        return max(include, exclude);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return helper(nums, 0, dp);
    }
};