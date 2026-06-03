class Solution:
    def assignBikes(self, workers, bikes):
        n= len(workers)
        m= len(bikes)

        cost = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                cost[i][j] = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])
        
        # we will use masking here 
        # 000..000 (m times) means all bikes are available
        # 111..111 (m times) means all bikes are assigned
        dp = [float('inf')] * (1 << m) #means 2^m possible states of bike assignment
        dp[0] = 0 # no bikes assigned, cost is 0

        for mask in range(1 << m):
            worker,idx = bin(mask).count('1'),0
            for j in range(m):
                if mask & (1 << j) == 0: #if bike is not assigned
                    dp[mask | (1<<j)] = min(dp[mask | (1<<j)], dp[mask]+ cost[worker][j])
        return dp[-1] #return the cost when all bikes are assigned
    