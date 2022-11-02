//problem link: https://leetcode.com/problems/single-number/

class Solution {
    public int singleNumber(int[] nums) {
        int sum = 0;
        for (int i = 0; i <nums.length; i++) {
            sum ^= nums[i];
        }
        return sum;
    }
}