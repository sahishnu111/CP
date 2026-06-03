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
    int n, q;
    cin >> n >> q;

    vi a(n + 1, 0), freq(q + 5, 0), ans(q + 5, 0);

    freq[0] = n;

    int f = 0;
    int zeroCnt = n;

    while (q--) {
        int v, t;
        cin >> v >> t;

        if (v == 1) {
            int oldVal = a[t];

            freq[oldVal]--;

            if (oldVal == f) {
                zeroCnt--;
            }

            a[t]++;

            int newVal = a[t];

            freq[newVal]++;
            if (newVal < ans.size()) {
                ans[newVal]++;
            }

            if (zeroCnt == 0) {
                f++;
                zeroCnt = freq[f];
            }

        } else {
            int re = t + f;
            
            if (re < ans.size()) {
                cout << ans[re] << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
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