#include <vector>
#include <algorithm>

class Solution {
public:
    int finalElement(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        // Alice can guarantee the larger of the two endpoints
        // by deleting everything else in one contiguous block.
        return std::max(nums[0], nums[n - 1]);
    }
};