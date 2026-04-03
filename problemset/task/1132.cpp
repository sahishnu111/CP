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


int BFSfardest(vector<vector<int>> &adj, int start) {
    queue<int> q;
    int n = adj.size();
    vector<int> dist(n, -1);
    dist[start] = 0;
    q.push(start);
    int fartestNode = start;
    int maxDist = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > maxDist) {
                    maxDist = dist[v];
                    fartestNode = v;
                }
            }
        }
    }
    return fartestNode;
}

vector<int> BFS(vector<vector<int>> &adj,int start){
    queue<int> q;
    int n=adj.size();
    vector<int> dist(n,-1);
    dist[start]=0;
    q.push(start);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(v!=u){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
    }
    return dist;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    forn(i,n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(n==1){
        cout << 0 << endl;
        return;
    }
    //fardest Node from 0
    int A=BFSfardest(adj,0);
    //fardest Node from A
    int B=BFSfardest(adj,A);
    //distance from A and B
    vector<int> distA=BFS(adj,A);
    vector<int> distB=BFS(adj,B);
    for(int i=0;i<n;i++){
        cout << max(distA[i],distB[i]) << " ";
    }
    cout << endl;
    

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