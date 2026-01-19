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

ll minX, maxX, minY, maxY;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    void dfs(int node, vector<bool> &visited, vector<pll> &cows) {
        visited[node] = true;

        
        minX = min(minX, cows[node].F);
        maxX = max(maxX, cows[node].F);
        minY = min(minY, cows[node].S);
        maxY = max(maxY, cows[node].S);

        for (auto &v : adj[node]) {
            if (!visited[v]) {
                dfs(v, visited, cows);
            }
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pll> cows(n);
    forn(i, n) {
        cin >> cows[i].F >> cows[i].S;
    }

    Graph g(n);

    forn(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.addEdge(a, b);
    }

    vector<bool> visited(n, false);
    ll ans = inf;

    forn(i, n) {
        if (!visited[i]) {
            minX = minY = inf;
            maxX = maxY = -inf;

            g.dfs(i, visited, cows);

            ll perimeter = 2 * ((maxX - minX) + (maxY - minY));
            ans = min(ans, perimeter);
        }
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
