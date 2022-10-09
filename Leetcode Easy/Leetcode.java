   \// java function to return true if contain duplicate 
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i=0;i<=nums.length-2;i++)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
    
