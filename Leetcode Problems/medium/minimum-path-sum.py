class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        h=len(grid)
        w=len(grid[0])
        if h==0:
            return 0
        for i in range(1,w):
            grid[0][i]+=grid[0][i-1]
        
        for i in range(1,h):
            for j in range(w):
                if j==0:
                    grid[i][j]+=grid[i-1][j]
                else:
                    grid[i][j]+=min(grid[i-1][j],grid[i][j-1])
        return grid[h-1][w-1]