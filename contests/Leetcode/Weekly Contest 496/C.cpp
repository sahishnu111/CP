#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        // dp[i][0] = {max_peaks, min_cost} if i IS a peak
        // dp[i][1] = {max_peaks, min_cost} if i is NOT a peak
        vector<vector<pair<int, long long>>> dp(n, vector<pair<int, long long>>(2, {0, 0}));

        // We start from 1 because index 0 can never be a peak
        for (int i = 1; i < n - 1; i++) {
            long long cost = max(0LL, (long long)max(nums[i-1], nums[i+1]) - nums[i] + 1);
            
            // Case 1: i IS a peak 
            // If i is a peak, i-1 MUST NOT be a peak
            dp[i][0].first = dp[i-1][1].first + 1;
            dp[i][0].second = dp[i-1][1].second + cost;

            // Case 2: i is NOT a peak
            // We pick the best option between (i-1 was a peak) and (i-1 was NOT a peak)
            if (dp[i-1][0].first > dp[i-1][1].first) {
                dp[i][1] = dp[i-1][0];
            } else if (dp[i-1][1].first > dp[i-1][0].first) {
                dp[i][1] = dp[i-1][1];
            } else {
                // If peaks are equal, minimize the cost
                dp[i][1].first = dp[i-1][0].first;
                dp[i][1].second = min(dp[i-1][0].second, dp[i-1][1].second);
            }
        }

        // The answer is the best state at n-2 (the last possible peak index)
        int last = n - 2;
        if (dp[last][0].first > dp[last][1].first) {
            return dp[last][0].second;
        } else if (dp[last][1].first > dp[last][0].first) {
            return dp[last][1].second;
        } else {
            return min(dp[last][0].second, dp[last][1].second);
        }
    }
};