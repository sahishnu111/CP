#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)x.size()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define mod 998244353
#define inf 1e18

void solve() {
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));

    vector<int> dp(5005, 0);

    dp[0] = 1;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        // 1. Calculate contributions
        for (int s = 0; s <= 5000; s++) {
            if (dp[s] == 0) continue;

            long long currS = s + a[i];
            long long currM = a[i];
            long long grp = max(currM, (currS + 1) / 2);

            ans = (ans + dp[s] * (grp % mod)) % mod;
        }

        // 2. Update Knapsack DP safely
        for (int s = 5000 - a[i]; s >= 0; s--) {
            dp[s + a[i]] = (dp[s + a[i]] + dp[s]) % mod;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        solve();
    }
    return 0;
}