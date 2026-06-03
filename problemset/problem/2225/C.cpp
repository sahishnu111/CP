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
#define mod 1000000007
#define inf 1e18

void solve() {
    int n;
    cin >> n;

    vector<string> grid(2);
    cin >> grid[0] >> grid[1];

    vector<int> dp(n + 1, 1e9);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {

        // vertical domino in column i
        int cost = (grid[0][i - 1] != grid[1][i - 1]);
        dp[i] = min(dp[i], dp[i - 1] + cost);

        // two horizontal dominoes using columns i-1 and i
        if (i >= 2) {
            int cost2 = 0;

            if (grid[0][i - 1] != grid[0][i - 2])
                cost2++;

            if (grid[1][i - 1] != grid[1][i - 2])
                cost2++;

            dp[i] = min(dp[i], dp[i - 2] + cost2);
        }
    }

    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test = 1;
    cin >> test;

    while (test--) {
        solve();
    }

    return 0;
}