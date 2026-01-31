#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

struct Edge {
    int to;
    int id;
};

class Graph {
public:
    int V;
    vector<vector<Edge>> adj;

    Graph(int n) {
        V = n;
        adj.resize(n);
    }

    void add_edge(int u, int v, int id) {
        adj[u].push_back({v, id});
        adj[v].push_back({u, id});
    }

    // BFS check for bipartite graph
    bool bfsBipartite(int start, vector<int>& color) {
        queue<int> q;
        color[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto e : adj[u]) {
                int v = e.to;
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    return false; // not bipartite
                }
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph g(n);
    vector<pair<int,int>> edges(m);

    // Read input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        g.add_edge(u, v, i);
    }

    // Bipartite coloring
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!g.bfsBipartite(i, color)) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    // Build answer
    vector<char> ans(m);
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        // Always direct from color 0 → color 1
        if (color[u] == 0 && color[v] == 1)
            ans[i] = '0'; // ui → vi
        else
            ans[i] = '1'; // vi → ui
    }

    cout << "YES\n";
    for (char c : ans) cout << c;
    cout << "\n";

    return 0;
}
