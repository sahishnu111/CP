#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int swaps = 0;
    while(left < right) {
        while(left < right && nums[left] != 0) left++;
        while(left < right && nums[right] == 0) right--;
        if(left < right) {
            swap(nums[left], nums[right]);
            swaps++;
            left++;
            right--;
        }
        
    }
    return swaps;
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