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

class DSU{
    public:
    vector<int> parent,sz;
    DSU(int n){
        parent.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

    bool UNION(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
        return true;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> E(n+1,vector<ll>(n+1,0));

    vector<pair<ll,pair<int,int>>> edges; // (weight,(u,v))

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll x;
            cin>>x;
            E[i][j]=x;
            E[j][i]=x;
            edges.push_back({x,{i,j}});
        }
    }

    sort(all(edges)); 

    // build a tree
    DSU Tree(n+1);
    vector<vector<pair<int,ll>>> tree(n+1); // tree[u] = {v,weight}
    int cnt=0;
    for(auto e:edges){
        ll w=e.F;
        int u=e.S.F;
        int v=e.S.S;

        if(Tree.UNION(u,v)){
            tree[u].push_back({v,w});
            tree[v].push_back({u,w});
            cnt++;
            if(cnt==n-1) break; 
        }
    }

    // BFS
    for(int s=1;s<=n;s++){
        vector<ll> dist(n+1,-1);
        dist[s]=0;
        queue<int> q;
        q.push(s);
        
        while(!q.empty()){
            int c=q.front(); q.pop();
            for(auto [nbh,w] : tree[c]){
                if(dist[nbh]==-1){
                    dist[nbh]=dist[c]+w;
                    if(dist[nbh]!=E[s][nbh]){
                        cout<<"No\n";
                        return;
                    }
                    q.push(nbh);
                }
            }
        }
    }

    cout<<"Yes\n";
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