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
#define mod 998244353 // Updated to problem specific modulo
#define inf 1e18

// Using your Extended Euclidean Algorithm for Mod Inverse
ll modInverse(ll q, ll m){
    ll m0 = m, t, x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (q > 1) {
        t = m / q;
        m = m % q, swap(m, q);
        x0 = x0 - t * x1, swap(x0, x1);
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

void solve() {
    int n, m; // Fixed typo (n.m -> n, m)
    if (!(cin >> n >> m)) return;
    
    vector<vector<int>> adj(n + 1); // Fixed initialization
    vector<int> deg(n + 1, 0);

    forn(i, m) {
        int u, v;
        cin >> u >> v; // p_u < p_v means v is boss of u
        adj[v].push_back(u);
        deg[u]++;
    }

    // dummy node 0 is boss for all nodes with degree 0
    for1(i, n) { // Changed to 1-based indexing for nodes
        if (deg[i] == 0) {
            adj[0].push_back(i);
            deg[i]++;
        }
    }

    // cycle check using Topological sort BFS iterative
    queue<int> q;
    q.push(0);
    
    vector<int> topo;
    while (!q.empty()) {
        int curr = q.front(); 
        q.pop();
        topo.push_back(curr);

        for (int nxt : adj[curr]) {
            deg[nxt]--;
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    // if topo size is not n+1 then there is a cycle
    if (topo.size() != n + 1) {
        cout << 0 << endl; // Problem asks for 0 on impossibility
        return;
    }

    // calculate the subtree size bottom up using topo order
    vector<ll> subTree(n + 1, 1); 

    for (int i = topo.size() - 1; i >= 0; i--) {
        int curr = topo[i];
        for (int nxt : adj[curr]) {
            subTree[curr] += subTree[nxt];
        }
    }

    // N! / (product of subtree sizes)
    ll prp = 1;
    for1(i, n) {
        prp = (prp * (subTree[i] % mod)) % mod;
    }

    ll num = 1;
    for1(i, n) {
        num = (num * i) % mod;
    }

    ll ans = (num * modInverse(prp, mod)) % mod;
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