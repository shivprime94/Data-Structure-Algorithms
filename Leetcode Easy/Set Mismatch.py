class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        freq = Counter(nums)
        ans = [-1, -1]
        for x in range(1, len(nums) + 1):
            if x not in freq:
                ans[1] = x
            if freq[x] > 1:
                ans[0] = x
        return ans