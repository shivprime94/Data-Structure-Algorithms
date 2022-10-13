'''
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.
'''

from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        t=1
        a=set(nums)
        while t in a:
            t+=1
        return t

#Create object of Solution class
p1 = Solution()

lst=[]
n=int(input())
#input list from user
for i in range(n):
    ele=int(input())
    lst.append(ele)
print(p1.firstMissingPositive(lst))


'''
Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
'''


'''
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
'''


'''
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
'''
