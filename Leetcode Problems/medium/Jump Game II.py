class Solution:
    def jump(self, nums: List[int]) -> int:
        count=0
        n=len(nums)
        i=0
        while True:
            hold=nums[i]
            idx=i
            maximum=-1
            if idx>=n-1:
                return count
            for j in range(i+1,i+hold+1):
                if j>=n-1:
                    return count+1
                if maximum<j+nums[j]:
                    idx=j
                    maximum=j+nums[j]
            count+=1
            i=idx
        
                
                