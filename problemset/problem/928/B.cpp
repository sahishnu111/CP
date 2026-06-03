#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    // Use n+1 to keep things 1-indexed for simplicity
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> dp(n + 1, 0);
    vector<int> L(n + 1, 0);
    vector<int> R(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int currL = max(1, i - k);
        int currR = min(n, i + k);

        if (a[i] == 0) {
            // No link: just this message's window
            L[i] = currL;
            R[i] = currR;
            dp[i] = currR - currL + 1;
        } else {
            int prev = a[i];
            // Check if our current window touches the PREVIOUS block
            if (currL <= R[prev] + 1) {
                // Overlap: Merge the current window with the previous block
                // The new block starts where the previous block started
                L[i] = L[prev];
                R[i] = currR;
                dp[i] = (ll)R[i] - L[i] + 1;
            } else {
                // Gap: Current window is separate from the previous chain
                L[i] = currL;
                R[i] = currR;
                // Total is the old chain count + current window size
                dp[i] = dp[prev] + (currR - currL + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << (i == n ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}