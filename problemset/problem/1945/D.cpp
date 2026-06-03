#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; ++i)

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    ll suffix = 0;
    ll minCost = LLONG_MAX;

    for (int i = n - 1; i >= 0; i--) {
        if (i < m) {
            minCost = min(minCost, a[i] + suffix);
        }
        suffix += b[i];
    }

    cout << minCost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}