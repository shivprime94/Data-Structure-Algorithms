/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        int leftMax = height[0];
        int rightMax = height[n - 1];
        int l = 0, r = n - 1;
        int area = 0;
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= leftMax)
                {
                    leftMax = height[l];
                }
                else
                    area += leftMax - height[l];
                ++l;
            }
            else
            {
                if (height[r] >= rightMax)
                {
                    rightMax = height[r];
                }
                else
                    area += rightMax - height[r];
                --r;
            }
        }
        return area;
    }
};