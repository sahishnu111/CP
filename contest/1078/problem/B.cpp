#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

// Using two large primes for double hashing
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

// dp[k][s] stores number of ways to pick k items to reach sum s
ll dp1[101][10001];
ll dp2[101][10001];

// C[n][k] stores the expected binomial coefficient (n choose k)
ll C1[101][101];
ll C2[101][101];

void precompute_combinations() {
    for (int i = 0; i <= 100; i++) {
        C1[i][0] = C2[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C1[i][j] = (C1[i - 1][j - 1] + C1[i - 1][j]) % MOD1;
            C2[i][j] = (C2[i - 1][j - 1] + C2[i - 1][j]) % MOD2;
        }
    }
}

int main() {
    // Fast I/O for competitive programming
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute_combinations();

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        counts[a[i]]++;
    }

    // Base Case: 1 way to have 0 items summing to 0
    dp1[0][0] = dp2[0][0] = 1;

    // Standard 0/1 Knapsack DP (Counting Combinations)
    // We use each weight 'w' exactly once
    int current_max_sum = 0;
    for (int w : a) {
        current_max_sum += w;
        // Iterate k and s in REVERSE to maintain the 0/1 constraint
        for (int k = n; k >= 1; k--) {
            for (int s = current_max_sum; s >= w; s--) {
                dp1[k][s] = (dp1[k][s] + dp1[k - 1][s - w]) % MOD1;
                dp2[k][s] = (dp2[k][s] + dp2[k - 1][s - w]) % MOD2;
            }
        }
    }

    int max_revealed = 0;
    int distinct_types = counts.size();

    for (auto const& [mass, total_owned] : counts) {
        for (int k = 1; k <= total_owned; k++) {
            int target_sum = k * mass;

            // Check if the fingerprints match
            bool match1 = (dp1[k][target_sum] == C1[total_owned][k]);
            bool match2 = (dp2[k][target_sum] == C2[total_owned][k]);

            if (match1 && match2) {
                // Special Rule: If there are only 2 distinct masses in the set
                // and we successfully identify all of one type (k == total_owned),
                // we automatically know what the other type is.
                if (distinct_types == 2 && k == total_owned) {
                    max_revealed = n;
                } else {
                    max_revealed = max(max_revealed, k);
                }
            }
        }
    }

    cout << max_revealed << endl;

    return 0;
}