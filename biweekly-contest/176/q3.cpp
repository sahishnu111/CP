#include <bits/stdc++.h>
using namespace std;

long long mS = 0;

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<array<unordered_map<int,long long>,2>> dp(n);
        mS = backtrach(nums, colors, 0, -1, 1, dp);
        return mS;
    }
    
    long long backtrach(vector<int> &nums, vector<int> &colors, int idx, int pc, int pidx, vector<array<unordered_map<int,long long>,2>> &dp){
        if(idx == (int)nums.size()){
            return 0;
        }
        int f = (pidx == 1) ? -1 : pc;
        
        auto it = dp[idx][pidx].find(f);
        if(it != dp[idx][pidx].end()){
            return it->second;
        }

        long long sum = backtrach(nums, colors, idx+1, f, 1, dp);

        if(pidx == 1 || colors[idx] != pc){
            sum = max(sum, nums[idx] + backtrach(nums, colors, idx+1, colors[idx], 0, dp));
        }

        dp[idx][pidx][f] = sum;
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution sol;
    vector<int> nums = {10,1,3,9};
    vector<int> colors = {1,1,1,2};
    cout << sol.rob(nums, colors) << endl;  
    return 0;
}
