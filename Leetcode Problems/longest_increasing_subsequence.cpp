class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > v.back())
                v.push_back(nums[i]);
            else
            {
                int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[idx] = nums[i];
            }
        }
        return v.size();
    }
};