/* 
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
You must solve it in O(n) time complexity.

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/

#include<queue>
#include<vector>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        for(int i=0;i<k-1;i++)
        {
            pq.pop();
        }
        return pq.top();
        
        
    }
};