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
    int nodes;
    vector<vector<int>> adj;
    public:
        Graph(int n){
            this->nodes=n;
            adj.resize(n+1);
        }

        void add_edge(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> distanceFromNode(int start){
            vector<bool> visited(nodes,false);
            queue<int> q;
            vector<int> distance(nodes,0);
            visited[start]=true;
            q.push(start);
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(auto nbh: adj[curr]){
                    if(!visited[nbh]){
                        visited[nbh]=true;
                        distance[nbh]=distance[curr]+1;
                        q.push(nbh);
                    }
                }
            }

            return distance;
        }

        int furthestNode(int start){
            vector<int> distance=distanceFromNode(start);
            int mxDist=-1;
            int node=-1;
            forn(i,nodes){
                if(distance[i]>mxDist){
                    mxDist=distance[i];
                    node=i;
                }
            }

            return node;
        }
};

void solve() {
    int n;
    cin>>n;
    Graph g(n);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        g.add_edge(u,v);
    }

    int nodeA=g.furthestNode(0);
    int nodeB=g.furthestNode(nodeA);

    vector<int> distA=g.distanceFromNode(nodeA);
    vector<int> distB=g.distanceFromNode(nodeB);
    
    /*
    for(int i=0;i<n;i++){
        cout<<max(distA[i],distB[i])<<" "; //eccentricity of node i
    }
    
    */

    

    //For which values of k does node i have at least one edge?
    // k from 0 to n-1
    
    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; i++) {
        int mx = max(distA[i], distB[i]);
        int death = mx + 1;
        cnt[death]++;
    }

    for (int k = 1; k <= n; k++) {
        cnt[k] += cnt[k - 1];
    }

    for (int k = 1; k <= n; k++) {
        int dead = cnt[k];
        int alive = n - dead;

        int components;
        if (alive > 0) {
            components = dead + 1;
        } else {
            components = n;
        }

        cout << components << (k == n ? '\n' : ' ');
    }
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
