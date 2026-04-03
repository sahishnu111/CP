#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void CoinCombinationsI() {
    int n, x;
    if (!(cin >> n >> x)) return;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp[i] = number of ways to make sum i
    vector<long long> dp(x + 1, 0);
    dp[0] = 1; // Base case: 1 way to make sum 0 (using no coins)

    // OUTER LOOP: The target sum
    for (int i = 1; i <= x; i++) {
        // INNER LOOP: Try every coin for the current sum
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0) {
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
            }
        }
    }
    
    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    CoinCombinationsI();
    return 0;
}