#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums of length n and an integer k.

For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

In other words:

    max(nums[0..i]) is the largest value among the elements from index 0 to index i.
    min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.

An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.©leetcode

*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> pM(n);
        pM[0] = nums[0];
        for(int i = 1; i <n;i++){
        pM[i] = max(pM[i-1], nums[i]);
        }

        vector<int> sM(n);
        sM[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            sM[i] = min(sM[i+1], nums[i]);
        }

        int ans = -1;
        for(int i = 0; i < n; i++){
            if(pM[i] - sM[i] <= k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        // Input reading can be added here if needed
        Solution sol;
        // Call the relevant function from sol and print the result
    }
    return 0;
}