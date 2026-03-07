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
    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> v(n + 1);
    for1(i, n) {
        cin >> v[i].F >> v[i].S;
    }

    // dp[i][j] = max prft last town is i with cost j
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -inf));

    ll ans = 0;

    for1(i, n) {
        for (int j = v[i].S; j <= m; j++) {
            // strt i
            dp[i][j] = v[i].F;

            // ext k
            for (int l = max(1, i - k); l < i; l++) {
                dp[i][j] = max(dp[i][j], dp[l][j - v[i].S] + v[i].F);
            }

            ans = max(ans, dp[i][j]);
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
