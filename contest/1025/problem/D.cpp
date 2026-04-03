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
    if (!(cin >> n)) return;
    vi a(n);
    forn(i, n) cin >> a[i];

    vector<vector<bool>> L(n, vector<bool>(n, false));
    vector<vector<bool>> R(n, vector<bool>(n, false));

    vector<vector<bool>> adj(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (__gcd(a[i], a[j]) > 1) adj[i][j] = true;
        }
    }

    // Fixed the loop condition: changed "i <= n" to "len <= n"
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {
                
                // Logic check: lft uses L and rgt uses R
                int lft = (k == i) ? 1 : L[i][k - 1];
                int rgt = (k == j) ? 1 : R[k + 1][j];

                if (lft && rgt) {
                    // Can it connect to parent at j+1 (as a left child)?
                    if (j + 1 < n && adj[k][j + 1]) L[i][j] = true;

                    // Can it connect to parent at i-1 (as a right child)?
                    if (i - 1 >= 0 && adj[k][i - 1]) R[i][j] = true;
                }
            }
        }
    }

    bool possible = false;
    for (int k = 0; k < n; k++) {
        int lft = (k == 0) ? 1 : L[0][k - 1];
        int rgt = (k == n - 1) ? 1 : R[k + 1][n - 1];

        if (lft && rgt) {
            possible = true;
            break;
        }
    }

    cout << (possible ? "Yes" : "No") << endl;
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