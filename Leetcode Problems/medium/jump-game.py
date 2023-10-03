class Solution:
    def canJump(self, nums: List[int]) -> bool:
        mr=0
        #n=len(nums)
        if len(nums)==1:
            return True
        for i in range(len(nums)):
            if (i+nums[i]>mr):
                mr=i+nums[i]
            if i==mr:
                break
        return mr>=len(nums)-1