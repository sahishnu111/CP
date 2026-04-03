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
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    for (int i = 0; i < n; i++) {
        if (i < n - k || i >= k) { 
            if (b[i] != -1 && b[i] != a[i]) {
                cout << "NO\n";
                return;
            }
        }
    }

    if (n - k < k) {
        vector<int> f(n + 1, 0);

        for (int i = n - k; i < k; i++) {
            f[a[i]]++;
        }
        
        for (int i = n - k; i < k; i++) {
            if (b[i] != -1) {
                f[b[i]]--;
                if (f[b[i]] < 0) { 
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
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