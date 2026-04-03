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

// Use 1e9 for int infinity, as 1e18 is for long long
const int INF = 1e9;

int n;
int a[200005];
int memo[200005][2];

// Changed return type to int
int dfs(int i, int turn) {
    if (i >= n) return 0; // Tower cleared
    if (memo[i][turn] != -1) return memo[i][turn];

    int res = INF;
    if (turn == 0) {
        // Friend's turn: Friend kills 1 boss
        res = min(res, a[i] + dfs(i + 1, 1));
        // Friend kills 2 bosses
        if (i + 1 < n) {
            res = min(res, a[i] + a[i + 1] + dfs(i + 2, 1));
        }
    } else {
        // Your turn: You kill 1 boss
        res = min(res, dfs(i + 1, 0));
        // You kill 2 bosses
        if (i + 1 < n) {
            res = min(res, dfs(i + 2, 0));
        }
    }

    return memo[i][turn] = res;
}

void solve() {
    cin >> n; // Read n for each test case
    forn(i, n) {
        cin >> a[i];
        // Only clear the memo for the parts of the array we will use
        memo[i][0] = -1;
        memo[i][1] = -1;
    }
    
    // Output the result of the recursive function
    cout << dfs(0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test; // Read number of test cases
    while (test--) {
        solve();
    }
    return 0;
}