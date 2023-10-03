class Solution:
    def partition(self, s):
        def find_all_palindromes(s):
            B = [0] * (2*n)
            for i, j in combinations_with_replacement(range(n), 2):
                if s[i:j+1] == s[i:j+1][::-1]:
                    B[i+j+1] = max(B[i+j+1], j-i+1)
            return B
        
        n = len(s)
        B = find_all_palindromes(s)
        
        dp = [[] for _ in range(n+1)]
        dp[0] = [[]]
        for i in range(0, n):
            for k in range(0, i+1):
                if B[2*i-k+1] >= k:
                    for elem in dp[i-k]:
                        dp[i + 1].append(elem  + [s[i-k:i+1]])

        return dp[-1]