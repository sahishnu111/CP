#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i,n) for(int i=0;i<n;i++)

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

    
    vector<int> minDistFromRoot(int src) {
        vector<int> dist(V, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }

    // DFS for Bob's escape (only move away from Alice)
    int dfs(int node, vector<bool> &visited, vector<int> &dist) {
        visited[node] = true;
        int maxDist = 0;

        for (auto &v : adj[node]) {
            if (!visited[v] && dist[v] > dist[node]) {
                int d = dfs(v, visited, dist);
                maxDist = max(maxDist, d + 1);
            }
        }
        return maxDist;
    }
};

void solve() {
    int n, x;
    cin >> n >> x;
    x--;   
    Graph g(n);

    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.addEdge(u, v);
    }

    
    vector<int> dist = g.minDistFromRoot(0);

    int d1 = dist[x];   

    vector<bool> visited(n, false);
    int d2 = g.dfs(x, visited, dist);  

    cout << 2 * max(d1, d2) << '\n';
}


int bfs(int strt)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
