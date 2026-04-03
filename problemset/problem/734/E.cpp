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

// Your graph compression function, modified slightly to map nodes to their component "leader"
unordered_map<int,int> graphCompression(vector<vector<int>> &adj, vector<int> &color, int node, vector<int> &leader) {
    unordered_map<int,int> visited;
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    leader[node] = node; // The start node is the "leader" of this colored component
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            // If same color and not visited, group them together
            if(visited.find(v) == visited.end() && color[v] == color[u]){
                visited[v] = 1;
                leader[v] = node; // Assign the same leader
                q.push(v);
            }
        }
    }
    return visited;
}

// Your BFS function, modified to return max distance and update farthestNode
int BFS(unordered_map<int, vector<int>> &compressedGraph, int start, int &farthestNode) {
    queue<int> q;
    unordered_map<int,int> dist;
    q.push(start);
    dist[start] = 0;
    farthestNode = start;
    int maxDist = 0;
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : compressedGraph[u]){
            if(dist.find(v) == dist.end()){
                dist[v] = dist[u] + 1;
                if(dist[v] > maxDist) {
                    maxDist = dist[v];
                    farthestNode = v;
                }
                q.push(v);
            }
        }
    }
    return maxDist;
}

void solve() {
    int n;
    cin >> n;
    vector<int> color(n);
    forn(i, n) cin >> color[i];

    vector<vector<int>> adj(n);
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // compressGraph needs to hold multiple neighbors, so value is vector<int>
    unordered_map<int, vector<int>> compressGraph;
    unordered_map<int, int> visited;
    vector<int> leader(n); // Array to remember which compressed node an original node belongs to

    // 1. Group nodes of the same color
    forn(i, n){
        if(visited.find(i) == visited.end()){
            // Get the visited map from your function
            unordered_map<int,int> compVisited = graphCompression(adj, color, i, leader);
            
            // Merge it into the main visited map
            for(auto kv : compVisited) {
                visited[kv.first] = 1;
            }
        }
    }

    // 2. Build the compressed graph edges
    // If two adjacent original nodes have different colors, connect their leaders!
    forn(u, n) {
        for(int v : adj[u]) {
            if(color[u] != color[v]) {
                compressGraph[leader[u]].pb(leader[v]);
            }
        }
    }

    // 3. Find diameter using your BFS logic
    int startNode = leader[0]; // Start from the leader of node 0
    int farthestNode = startNode;
    
    // First BFS to find one end of the diameter
    BFS(compressGraph, startNode, farthestNode);
    
    // Second BFS from the farthest node to find the actual diameter
    int diameter = BFS(compressGraph, farthestNode, farthestNode);

    // Answer is ceiling of diameter/2
    cout << (diameter + 1) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}