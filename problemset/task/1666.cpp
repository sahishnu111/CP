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

class Graph {
public:
    int node;
    vector<vector<int>> adj_list;

    Graph(int x) {
        node = x;
        adj_list.resize(x);
    }
};

void solve() {
    int node, edges;
    cin >> node >> edges;

    Graph g(node);

    for (int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--; // Assuming input is 1-indexed

        g.adj_list[x].pb(y);
        g.adj_list[y].pb(x);
    }

    // DFS to count connected components
    vector<bool> visited(node, false);
    int cnt = 0;
    vector<int> reps;

    for (int i = 0; i < node; i++) {
        if (!visited[i]) {
            cnt++;
            reps.pb(i);

            stack<int> s;
            s.push(i);
            visited[i] = true;

            while (!s.empty()) {
                int u = s.top();
                s.pop();

                for (int v : g.adj_list[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        s.push(v);
                    }
                }
            }
        }
    }

    cout << cnt-1 << endl;
    // The number of edges needed to connect all components is (number of components - 1)
    // any edges to connect components are
    for(int i = 1; i < cnt; i++) {
        cout << reps[i - 1] + 1 << " " << reps[i] + 1 << endl; // converting back to 1-indexed
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
