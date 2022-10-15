class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // bottom-up approach
        int n = nums.size();
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0] = nums[0];
        if (n == 1)
            return dp1[0];
        dp2[0] = nums[1];
        dp1[1] = max(nums[0], nums[1]);
        if (n == 2)
            return dp1[1];
        dp2[1] = max(nums[1], nums[2]);
        for (int i = 2; i < n - 1; i++)
        {
            dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);
        }
        for (int i = 2; i < n - 1; i++)
        {
            dp2[i] = max(nums[i + 1] + dp2[i - 2], dp2[i - 1]);
        }
        return max(dp1[n - 2], dp2[n - 2]);
    }
};