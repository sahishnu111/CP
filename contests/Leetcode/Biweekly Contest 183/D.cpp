

#define MOD 1000000007 

class Solution {
public:
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = parent.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k, 0)));
        
        for(int i = 0; i < n; i++){
            // base case
            dp[i][0][0] = 1;
            dp[i][1][nums[i] % k] = 1;
        }

        for(int i = n - 1; i > 0; i--){
            int p = parent[i];
            int c = i;

            vector<int> dp1(k, 0); 
            vector<int> dp2(k, 0); 

            // knapsack
            for(int rp = 0; rp < k; rp++){ 
                
                if(dp[p][0][rp] > 0){
                    for(int rc = 0; rc < k; rc++){
                        int wc = (dp[c][0][rc] + dp[c][1][rc]) % MOD;
                        int R = (rp + rc) % k;
                
                        dp1[R] = (dp1[R] + (long long)dp[p][0][rp] * wc) % MOD;
                    }
                }
                if(dp[p][1][rp] > 0){ 
                    for(int rc = 0; rc < k; rc++){
                        int wc = dp[c][0][rc];
                        int R = (rp + rc) % k;
                        
                        
                        dp2[R] = (dp2[R] + (long long)dp[p][1][rp] * wc) % MOD;
                    }
                }
            }
            dp[p][0] = dp1;
            dp[p][1] = dp2;
        }

        
        int total = (dp[0][0][0] + dp[0][1][0]) % MOD;
        
        
        return (total - 1 + MOD) % MOD;
    }
};