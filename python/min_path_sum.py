'''
Min-path-sum :- Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

'''

class Solution:

      # Memoize
#     def solve(self,m,n,grid,dp):
#         if m == 0 and n == 0:
#             return grid[0][0]
        
#         if m < 0 or n < 0:
#             return int(1e9)
        
#         if dp[m][n] != -1: return dp[m][n]
        
#         first = grid[m][n] + self.solve(m-1,n,grid,dp)
#         second = grid[m][n] + self.solve(m,n-1,grid,dp)
        
#         dp[m][n] = min(first,second)
#         return dp[m][n]


      # Tabulation
#     def solve(self,m,n,grid,dp):
#         for i in range(m):
#             for j in range(n):
#                 if  i == 0 and j == 0:
#                     dp[i][j] = grid[0][0]
#                 else:
#                     first = grid[i][j]
#                     if i-1 >= 0:
#                         first += dp[i-1][j]
#                     else:
#                         first += int(1e9)

#                     second = grid[i][j]
#                     if j-1 >= 0:
#                         second += dp[i][j-1]
#                     else:
#                         second += int(1e9)

#                     dp[i][j] = min(first,second)
                
#         return dp[m-1][n-1]

    # Space Optimization
    def solve(self,m,n,grid):
        prev = [0]*n
        for i in range(m):
            curr = [0]*n
            for j in range(n):
                if  i == 0 and j == 0:
                    curr[j] = grid[0][0]
                else:
                    first = grid[i][j]
                    if i-1 >= 0:
                        first += prev[j]
                    else:
                        first += int(1e9)

                    second = grid[i][j]
                    if j-1 >= 0:
                        second += curr[j-1]
                    else:
                        second += int(1e9)

                    curr[j] = min(first,second)
            prev = curr
                
        return prev[n-1]
        
        
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = self.solve(m,n,grid)
        return res
        