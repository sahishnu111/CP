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
#define inf 8e18 

ll ans, target;
int nlen, d1, d2;
string s;

void dfs(int idx, ll curr, int state) {
    if (idx == nlen) {
        ans = min(ans, abs(curr - target));
        return;
    }

    if (state == -1) {
        dfs(idx + 1, curr * 10 + d2, -1);
        return;
    }
    if (state == 1) {
        dfs(idx + 1, curr * 10 + d1, 1);
        return;
    }

    int digi = s[idx] - '0';

    int nxt = 0;
    if (d1 < digi) nxt = -1;
    else if (d1 > digi) nxt = 1;
    dfs(idx + 1, curr * 10 + d1, nxt);

    if (d1 != d2) {
        int nxti = 0;
        if (d2 < digi) nxti = -1;
        else if (d2 > digi) nxti = 1;
        dfs(idx + 1, curr * 10 + d2, nxti);
    }
}

void solve() {
    ll a;
    int n, b1, b2;
    cin >> a >> n >> b1 >> b2;

    if (b1 > b2) swap(b1, b2);
    
    d1 = b1;
    d2 = b2;
    target = a;
    s = to_string(a);
    
    nlen = sz(s);
    ans = inf;

    if (nlen > 1) {
        ll val = 0;
        forn(i, nlen - 1) {
            val = val * 10 + d2;
        }
        ans = min(ans, abs(a - val));
    }

    ll valL = 0;
    if (d1 == 0) {
        valL = d2; 
        forn(i, nlen) {
            valL = valL * 10 + d1; 
        }
    } else {
        forn(i, nlen + 1) {
            valL = valL * 10 + d1; 
        }
    }
    ans = min(ans, abs(a - valL));

    dfs(0, 0, 0);
    
    cout << ans << endl;
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