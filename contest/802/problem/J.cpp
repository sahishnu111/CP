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

int ans=0;

int dfs(int node,const vector<vector<pair<int,int>>> &adj,vector<int> &vis,int c){
    if( vis[node] ) return 0;
    vis[node]=1;

    ans=max(ans,c);
    vi cost;
    for(auto &e:adj[node]){
        int v=e.first;
        dfs(v,adj,vis,c+e.second);
        cost.pb(c+e.second);

    }

    return max(0,*max_element(all(cost))); ;
    
}




void solve() {
    // Your code here
    int V;
    cin>>V;
    vector<vector<pair<int,int>>> adj(V);
    forn(i,V){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].pb({v,c});
    }

    vector<int> vis(V,0);
    dfs(0,adj,vis);

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