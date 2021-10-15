import java.util.*;

class Solution {
    public int subarraySum(int[] nums, int k) {
        int[] sums = new int[nums.length];
        sums[0] = nums[0];
        int num = 0;
        for(int i = 1; i < nums.length; i++){
            sums[i] = sums[i-1] + nums[i];
        }
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == k) num++;
            if(i==0){
                for(int j = i + 1; j < nums.length; j++){
                    if(sums[j] == k) num++;
                }
            }
            else{
                for(int j = i + 1; j < nums.length; j++){
                    if(sums[j] - sums[i-1] == k) num++;
                }
            }
        }
        return num;
    }
}
