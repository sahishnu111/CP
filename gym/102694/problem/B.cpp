#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; ++i)

// Returns the node farthest from 'start'
int BFSfurtheset(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    int furthestNode = start;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > dist[furthestNode]) {
                    furthestNode = v;
                }
            }
        }
    }
    return furthestNode;
}

// Returns a vector of distances from 'start' to all other nodes
vector<int> BFS(vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<int> dist(n, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Base case: If there is 1 node, adding node 2 creates a diameter of 1.
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    vector<vector<int>> adj(n);
    forn(i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--; y--; // 0-indexed for adjacency list
        adj[x].pb(y);
        adj[y].pb(x);
    }

    // 1. Find the two endpoints of the tree's diameter (U and V)
    int U = BFSfurtheset(0, adj);
    int V = BFSfurtheset(U, adj);

    // 2. Calculate the distance from every node to both U and V
    vector<int> distU = BFS(adj, U);
    vector<int> distV = BFS(adj, V);

    // 3. Calculate the diameter of the original tree
    int D = distU[V];

    // 4. For each node, output the maximum possible diameter if n+1 is attached
    forn(i, n) {
        // The farthest distance from node 'i' to any other node in the original tree
        int max_dist_from_i = max(distU[i], distV[i]);
        
        // The new diameter is either the original diameter, 
        // or the path starting from the new node -> i -> farthest node
        cout << max(D, max_dist_from_i + 1) << endl;
    }
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // This problem format has exactly one test case per execution
    solve();
    
    return 0;
}