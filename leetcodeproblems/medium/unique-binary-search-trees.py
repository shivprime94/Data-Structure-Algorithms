class Solution:
    def numTrees(self, n: int) -> int:
        if n<2:
            return 1
        s=[0]*(n+1)
        s[0]=1
        s[1]=1
        for i in range(2,n+1):
            for j in range(0,i):
                s[i]+=s[j]*s[i-j-1]
        
        return s[-1]