class Solution:
    def dfs(self, grid, row, col, cnt0, cnt1, visited, dp):
        # bounds check
        if row < 0 or col < 0 or row >= len(grid) or col >= len(grid[0]):
            return False

        # include current cell
        if grid[row][col] == 0:
            cnt0 += 1
        else:
            cnt1 += 1

        # memoization by state (row, col, diff)
        diff = cnt1 - cnt0
        key = (row, col, diff)
        if key in dp:
            return dp[key]

        # if at destination, compare counts
        if row == len(grid) - 1 and col == len(grid[0]) - 1:
            dp[key] = (cnt0 == cnt1)
            return dp[key]

        found = False
        # try moving down
        if row + 1 < len(grid):
            found = self.dfs(grid, row + 1, col, cnt0, cnt1, visited, dp)
        # try moving right only if not found yet
        if not found and col + 1 < len(grid[0]):
            found = self.dfs(grid, row, col + 1, cnt0, cnt1, visited, dp)

        dp[key] = found
        return found
        
    

    def isThereAPath(self, grid):
        # Your code goes here
        if not grid or not grid[0]:
            return False

        # path length must be even to split equally into 0s and 1s
        if (len(grid) + len(grid[0]) - 1) % 2 != 0:
            return False
        
        visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        dp = {}
        return self.dfs(grid, 0, 0, 0, 0, visited, dp)