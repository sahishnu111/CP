#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl '\n'

vector<ll> sz;
vector<ll> ans;
vector<vector<int>> adj;
int n;

// First DFS: Calculate subtree sizes and the answer for the root (node 0)
void dfs1(int u, int p, int depth) {
    sz[u] = 1;
    ans[0] += depth;
    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u, depth + 1);
            sz[u] += sz[v];
        }
    }
}

// Second DFS: Re-rooting logic to find answers for all other nodes
void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            // Re-rooting formula
            ans[v] = ans[u] - sz[v] + (n - sz[v]);
            dfs2(v, u);
        }
    }
}

void solve() {
    if (!(cin >> n)) return;
    adj.assign(n, vector<int>());
    sz.assign(n, 0);
    ans.assign(n, 0);

    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    dfs1(0, -1, 0);
    dfs2(0, -1);

    forn(i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}