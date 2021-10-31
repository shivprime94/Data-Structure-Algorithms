#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = target;
        int n = nums.size();
        int sum, t, diff = INT_MAX;
        int i, j, k;
        for (i = 0; i < n - 2; i++)
        {
            j = i + 1;
            k = n - 1;
            t = target - nums[i];
            while (j < k)
            {
                sum = nums[j] + nums[k];
                if (abs(t - sum) < diff)
                {
                    diff = abs(t - sum);
                    ans = nums[i] + sum;
                }

                if (sum < t)
                    ++j;
                else if (sum > t)
                    --k;
                else
                    break;
            }
        }
        return ans;
    }
};