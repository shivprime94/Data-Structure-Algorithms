/* Problem Statement ->
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.Return the max sliding window.

 
Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

/* Solution -> */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     int n = nums.size();
        if (n == 0 || k == 0) return {};

        vector<int> v(n-k+1);
        deque<int> d;

        for (int i = 0; i < n; ++i) {
            while (!d.empty() && d.front() <= i-k) d.pop_front();
            while (!d.empty() && nums[d.back()] < nums[i]) d.pop_back();
            d.push_back(i);
            if (i >= k-1) v[i+1-k] = nums[d.front()];
        }
        return v;
    }
   
};

/* Output ->
Your input - [1,3,-1,-3,5,3,6,7]
             3
Output - [3,3,5,5,6,7]
Expected - [3,3,5,5,6,7]
*/
