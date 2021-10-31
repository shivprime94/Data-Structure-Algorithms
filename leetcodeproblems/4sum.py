from collections import defaultdict
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        s=defaultdict(int)
        n=len(nums)
        ans=[]
        i=j=0
        while i<n-3:
            j=i+1
            while j<n-2:
                l=j+1
                r=n-1
                while l<r:
                    if(nums[i]+nums[j]+nums[l]+nums[r]==target):
                        if s[str(nums[i])+str(nums[j])+str(nums[l])+str(nums[r])]==0:
                            s[str(nums[i])+str(nums[j])+str(nums[l])+str(nums[r])]+=1
                            ans.append([nums[i],nums[j],nums[l],nums[r]])
                        l+=1
                        r-=1
                        while(l<r and nums[l]==nums[l-1]):
                            l+=1
                        while(l<r and nums[r]==nums[r+1]):
                            r-=1
                    elif(nums[i]+nums[j]+nums[l]+nums[r]>target):
                        r-=1
                    else:
                        l+=1
                j+=1
                while(j<n-2 and nums[j]==nums[j-1]):
                    j+=1
            i+=1
            while(i<n-3 and nums[i]==nums[i-1]):
                i+=1
                        
        return ans
                            