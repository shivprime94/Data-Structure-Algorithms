def twoSum(self, nums: List[int], target: int) -> List[int]:
   for i, val in enumerate(nums):
        first_index = i
        sec_num = target - val
        if sec_num in nums[i+1:] :
          return first_index,nums.index(sec_num,i+1)
