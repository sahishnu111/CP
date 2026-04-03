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

#define MOD 676767677

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        int s = abs(x - y);
        long long mn = 0;

        if (s == 0) {
            mn = 1;
        } else {
            for (int i = 1; i * i <= s; i++) {
                if (s % i == 0) {
                    mn++;
                    if (i * i != s) {
                        mn++; 
                    }
                }
            }
        }

        cout << mn % MOD << endl;

        for (int i = 0; i < x; i++) cout << 1 << " ";
        for (int i = 0; i < y; i++) cout << -1 << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}