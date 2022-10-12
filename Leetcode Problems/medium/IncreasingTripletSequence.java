//334. https://leetcode.com/problems/increasing-triplet-subsequence/

public class IncreasingTripletSequence
{
    public static void main(String[] args)
    {
        int[] nums = {1,2,3,4,5};
        boolean ans = increasingTriplet(nums);
        System.out.println(ans);
    }

    public static boolean increasingTriplet(int[] nums)
    {
        int small = Integer.MAX_VALUE;
        int big = Integer.MAX_VALUE;

        //Greedy
        for(int i=0; i<nums.length; i++)
        {
            if(nums[i] <= small)
                small = nums[i];
            else if (small <= nums[i] && nums[i] <= big)
                big = nums[i];
            else
                return true;
        }

        return false;
    }
}
