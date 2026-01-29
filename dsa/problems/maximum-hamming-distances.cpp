#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int popcount(int x, int y){
        int cnt = 0;
        int val = x ^ y;
        while(val){
            cnt += (val & 1);
            val = val >> 1;
        }
        return cnt;
    }
    vector<int> maxHammingDistances(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> bitCount(m, 0);
        
        // Count number of 1s at each bit position
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if((nums[i] >> j) & 1){
                    bitCount[j]++;
                }
            }
        }

        vector<int> result;
        for(int i = 0; i < n; i++){
            int maxDist = 0;
            for(int j = 0; j < m; j++){
                int currentBit = (nums[i] >> j) & 1;
                if(currentBit == 0){
                    // Flipping to 1 gives hamming distance of bitCount[j]
                    maxDist += bitCount[j];
                } else {
                    // Flipping to 0 gives hamming distance of (n - bitCount[j])
                    maxDist += (n - bitCount[j]);
                }
            }
            result.push_back(maxDist);
        }

        return result;
    }
};


int main(){
    Solution sol;
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> result = sol.maxHammingDistances(nums, m);
    for(int dist : result){
        cout << dist << " ";
    }

    return 0;

}