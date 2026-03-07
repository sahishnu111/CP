#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> leftuphill(n, 1); 
        vector<int> leftdownhill(n, 1); 

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) {
                leftuphill[i] = leftdownhill[i-1] + 1;
            } else if(nums[i] < nums[i-1]) {
                leftdownhill[i] = leftuphill[i-1] + 1;
            }
        }

        vector<int> rightuphill(n, 1); 
        vector<int> rightdownhill(n, 1); 

        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]) {
                rightuphill[i] = rightdownhill[i+1] + 1;
            } else if(nums[i] > nums[i+1]) {
                rightdownhill[i] = rightuphill[i+1] + 1;
            }
        }

        int mx = 0;
        
        for(int i = 0; i < n; i++) {
            mx = max({mx, leftuphill[i], leftdownhill[i]});
        }

        for(int i = 0; i < n; i++){
            if (i == 0) {
                if (n > 1) mx = max({mx, rightuphill[1], rightdownhill[1]});
                continue;
            }
            if (i == n - 1) {
                if (n > 1) mx = max({mx, leftuphill[n-2], leftdownhill[n-2]});
                continue;
            }

            if(nums[i-1] < nums[i+1]){
                mx = max(mx, leftdownhill[i-1] + rightdownhill[i+1]);
            } else if(nums[i-1] > nums[i+1]){
                mx = max(mx, leftuphill[i-1] + rightuphill[i+1]);
            } else {
                mx = max({mx, leftuphill[i-1], leftdownhill[i-1], rightuphill[i+1], rightdownhill[i+1]});
            }
        }

        return mx;
    }
};

struct AlternatingInfo {
    int uphill;
    int downhill;
    
    AlternatingInfo() : uphill(1), downhill(1) {}
};

class SolutionRefactored {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<AlternatingInfo> left(n);
        vector<AlternatingInfo> right(n);

        // Build left arrays
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) {
                left[i].uphill = left[i-1].downhill + 1;
            } else if(nums[i] < nums[i-1]) {
                left[i].downhill = left[i-1].uphill + 1;
            }
        }

        // Build right arrays
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]) {
                right[i].uphill = right[i+1].downhill + 1;
            } else if(nums[i] > nums[i+1]) {
                right[i].downhill = right[i+1].uphill + 1;
            }
        }

        int mx = 0;
        
        // Without removing any element
        for(int i = 0; i < n; i++) {
            mx = max({mx, left[i].uphill, left[i].downhill});
        }

        // Try removing element at position i
        for(int i = 0; i < n; i++){
            if (i == 0) {
                if (n > 1) mx = max({mx, right[1].uphill, right[1].downhill});
                continue;
            }
            if (i == n - 1) {
                if (n > 1) mx = max({mx, left[n-2].uphill, left[n-2].downhill});
                continue;
            }

            if(nums[i-1] < nums[i+1]){
                mx = max(mx, left[i-1].downhill + right[i+1].downhill);
            } else if(nums[i-1] > nums[i+1]){
                mx = max(mx, left[i-1].uphill + right[i+1].uphill);
            } else {
                mx = max({mx, left[i-1].uphill, left[i-1].downhill, 
                          right[i+1].uphill, right[i+1].downhill});
            }
        }

        return mx;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {2,1,3,2};
    cout << sol.longestAlternating(nums) << endl;

    return 0;
}