#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // For memset

using namespace std;

// --- 1. Global Constants & Arrays ---
// We use global variables to avoid Stack Overflow (256MB limit is heap/global, stack is small)
const int MAX_ISLAND = 30005;
const int OFFSET = 250; // Max deviation from initial jump 'd' is roughly 250
const int MAX_OFFSET_IDX = 505; // 250 negative + 250 positive + some buffer

int gems[MAX_ISLAND];       // Stores count of gems on each island
int dp[MAX_ISLAND][MAX_OFFSET_IDX]; // dp[island][jump_offset_index]

int main() {
    // Fast I/O is good practice in Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    if (!(cin >> n >> d)) return 0;

    // --- 2. Input Handling ---
    // Read gem locations and count them per island
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        gems[p]++; 
    }

    // --- 3. DP Initialization ---
    // Fill DP table with -1 to represent "unreachable"
    memset(dp, -1, sizeof(dp));

    // Base Case: The first jump is fixed from 0 to d.
    // Current Island: d
    // Jump Length used: d
    // Offset Index: (d - d) + OFFSET = 0 + 250 = 250
    dp[d][OFFSET] = gems[d];

    int max_gems = 0;

    // --- 4. The DP Transitions ---
    // Iterate through every island from 'd' up to the max possible island
    for (int i = d; i < MAX_ISLAND; ++i) {
        
        // Iterate through every possible jump offset we could have arrived with
        for (int j = 0; j < MAX_OFFSET_IDX; ++j) {
            
            // If this state is unreachable, skip it
            if (dp[i][j] == -1) continue;

            // Update global maximum (in case we stop jumping here)
            max_gems = max(max_gems, dp[i][j]);

            // Reconstruct the actual jump length from the offset index
            // j = (len - d) + OFFSET  =>  len = d + (j - OFFSET)
            int current_jump_len = d + (j - OFFSET);

            // Try the 3 possible next jumps: len-1, len, len+1
            for (int change = -1; change <= 1; ++change) {
                int next_jump_len = current_jump_len + change;
                int next_island = i + next_jump_len;

                // VALIDATION CHECKS:
                // 1. Jump length must be positive (> 0)
                // 2. Next island must be within map bounds (< 30001)
                // 3. New offset index must be within our array bounds
                if (next_jump_len > 0 && next_island < MAX_ISLAND) {
                    
                    int next_offset_idx = (next_jump_len - d) + OFFSET;

                    if (next_offset_idx >= 0 && next_offset_idx < MAX_OFFSET_IDX) {
                        // Transition: Update the next state with the max gems found so far
                        dp[next_island][next_offset_idx] = max(
                            dp[next_island][next_offset_idx], 
                            dp[i][j] + gems[next_island]
                        );
                    }
                }
            }
        }
    }

    // --- 5. Output ---
    cout << max_gems << endl;

    return 0;
}