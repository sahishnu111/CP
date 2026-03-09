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

void falshfind(vll &v, ll d) {
    int x = v.size();
    if (!x) return;

    ll lv = v[0];

    for (int i = 1; i < x; i++) {
        ll df = v[i] - lv;
        ll nd = df * i;

        if (d >= nd) {
            d -= nd;
            lv = v[i];
        } 
        else {
            ll ad = d / i;
            ll r = d % i;

            for (int j = 0; j < i; j++)
                v[j] = lv + ad + (j >= i - r);

            return;
        }
    }

    ll ad = d / x;
    ll r = d % x;

    for (int j = 0; j < x; j++)
        v[j] = lv + ad + (j >= x - r);
}

void solve() {
    int n, m;
    ll l;
    cin >> n >> m >> l;

    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vll d(m);

    ll la = 0;

    for (int i = 1; i <= n + 1; i++) {
        ll c = (i <= n ? a[i - 1] : l);
        ll dl = c - la;

        ll k = n - i + 1;
        ll x = min((ll)m, k + 1);

        vll v(d.end() - x, d.end());

        falshfind(v, dl);

        for (int j = 0; j < x; j++)
            d[m - x + j] = v[j];

        if (i <= n) {
            for (int j = m - 1; j > 0; j--)
                d[j] = d[j - 1];

            d[0] = 0;
        }

        la = c;
    }

    cout << d.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) solve();
}