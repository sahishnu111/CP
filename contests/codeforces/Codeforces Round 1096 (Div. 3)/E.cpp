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
    vi a(n);
    ll cubes = 0;

    forn(i, n) {
        cin >> a[i];
        cubes += a[i];
    }

    vi b = a; 
    sort(all(b));

    ll sx = 0;
    forn(i, n) {
        sx += min(a[i], b[i]);
    }

    ll mv = cubes - sx;

    map<int, int> pos;
    forn(i, n) {
        if (pos.find(b[i]) == pos.end()) {
            pos[b[i]] = i;
        }
    }

    int mx = 0;
    forn(i, n) {
        int j = pos[a[i]];
        int dp = (a[i] <= b[i]) + (b[j] <= a[j]);
        mx = max(mx, dp);
    }

    ll ans = max(mv, mv - 1 + mx); 
    cout << ans << endl; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}