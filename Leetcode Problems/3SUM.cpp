class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
            return ans;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int sum = 0 - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] == sum)
                {
                    ans.push_back(vector<int>({nums[i], nums[l], nums[r]}));
                    ++l;
                    --r;
                    while (nums[l] == nums[l - 1] && l < r)
                    {
                        ++l;
                    }
                    while (nums[r] == nums[r + 1] && r > l)
                    {
                        --r;
                    }
                }
                else if (nums[l] + nums[r] < sum)
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }
        }
        return ans;
    }
};