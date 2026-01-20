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

class Graph{
    public:
    int V;
    vector<vector<int>> adj;
    Graph(int V){
        this->V=V;
        adj.resize(V);
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> BFS(int src){
        vector<bool> visited(V,false);
        vector<int> parent(V,-1);
        queue<int> q;
        visited[src]=true;
        q.push(src);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    parent[v]=u;
                    q.push(v);
                }
            }
        }

        return parent;

    }

    void path(int source,int dest){
        // minimum path from source to dest
        vector<int> parent=BFS(source);
        
        if(parent[dest]==-1 && source!=dest){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        
        vector<int> path;
        // print path from source to dest
        for(int v=dest;v!=-1;v=parent[v]){
            path.push_back(v);
        }
        reverse(path.begin(),path.end());
        
        cout<<path.size()<<endl;
        for(auto v:path){
            cout<<v<<" ";
        }
        cout<<endl;

    }

};

void solve() {
    // Your code here
    int n,m;
    cin>>n>>m;


    // minuimun path length from 1 to n
    Graph g(n+1);
    forn(i,m){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.path(1,n);
    
    
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