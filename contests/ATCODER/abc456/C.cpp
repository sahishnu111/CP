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
    string s;
    cin >> s;
    int n = s.size();

    ll ans = 0;
    
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    ll len = 1;
    ans = (ans + len) % mod; 
    
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) {
            len++;
        } else {
            len = 1;
        }
        ans = (ans + len) % mod;
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