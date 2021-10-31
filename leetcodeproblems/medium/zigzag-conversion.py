from collections import defaultdict
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        arr=list(range(numRows))
        ans=defaultdict(list)
        for i in range(numRows-2,0,-1):
            arr.append(i)
        l=len(arr)
        for i in range(len(s)):
            x=i%l
            ans[arr[x]].append(s[i])
        p=""
        for i in range(numRows):
            p+="".join(ans[i])
        return p