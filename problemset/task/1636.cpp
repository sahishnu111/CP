#include <bits/stdc++.h>
using namespace std;

// Using a constant for the modulo
const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    if (!(cin >> n >> x)) return;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Using vector<int> instead of long long to save cache space
    // 10^6 ints = 4MB, which fits well in L3 cache
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int c : a) {
        for (int i = c; i <= x; i++) {
            dp[i] += dp[i - c];
            // Faster than using the % operator every time
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }

    cout << dp[x] << endl;
}

int main() {
    // Standard I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}