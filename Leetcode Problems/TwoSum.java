import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int size = nums.length;
        int tempOne;
        int tempTwo;
        int indexOne = 0;
        int indexTwo = 0;
        for(int i = 0; i<size; i++){
            tempOne = nums[i];
            for(int j = 0; j<size; j++){
                if(j==i){
                    continue;
                }
                else{
                    tempTwo = nums[j];
                    if(tempTwo+tempOne==target){
                        indexOne = i;
                        indexTwo = j;
                    }
                }
            }
        }
        int [] arr = {indexOne, indexTwo};
        return arr;
    }
}
