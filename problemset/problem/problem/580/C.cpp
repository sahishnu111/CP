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

int ans = 0;

int dfs(int node, int parent,
        const vector<vector<int>> &adj_list,
        const vector<int> &a,
        int cnt, int mx) {

    if (cnt > mx) {
        return 0;
    }

    // leaf node (excluding root case)
    if (parent != -1 && adj_list[node].size() == 1) {
        return 1;
    }

    int res = 0;
    for (auto &child : adj_list[node]) {
        if (child != parent) {
            if (a[child] == 1) {
                res += dfs(child, node, adj_list, a,
                           a[node] == 1 ? cnt + 1 : 1, mx);
            } else {
                res += dfs(child, node, adj_list, a, 0, mx);
            }
        }
    }
    return res;
}

void solve() {
    ans = 0;  // FIX

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }

    if (a[0] == 1) {
        ans = dfs(0, -1, adj_list, a, 1, q);
    } else {
        ans = dfs(0, -1, adj_list, a, 0, q);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
