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

struct Edge{
    int u,v;
};

int n,m;
vector<int> d;
vector<vector<pair<int,int>>> adj;
vector<int> used;
vector<int> vis;
vector<int> parity;

bool ok=true;

int dfs(int u,int pEdg){
    vis[u]=1;
    int mask = d[u];   // required parity at this node (0 or 1)

    for(auto &e:adj[u]){
        int v=e.first;
        int idx=e.second;
        if(idx == pEdg) continue;

        if(!vis[v]){
            int child = dfs(v,idx);
            mask ^= child;   // combine child's requirement
        }
    }

    // if mask == 1, we must take the parent edge to fix this subtree
    if(mask){
        if(pEdg != -1){
            used[pEdg] = 1;
        }
    }

    return mask;
}

void solve() {
    cin>>n>>m;

    if(n==1 && m==0){
        int x;
        cin>>x;
        if(x==1) cout<<-1<<endl;
        else cout<<0<<endl;
        return;
    }

    d.resize(n);
    int cnt = 0, ncnt = 0;
    forn(i,n){
        cin>>d[i];
        if(d[i]==1) cnt++;
        if(d[i]==-1) ncnt++;
    }

    // Fix -1 values so that total number of 1s is even
    for(int i=0;i<n && ncnt>0;i++){
        if(d[i]==-1){
            ncnt--;
            if(ncnt==0){
                d[i] = (cnt % 2);
                if(d[i]==1) cnt++;
            }else{
                d[i] = 0;
            }
        }
    }

    // If total required odd degrees is odd, impossible
    if(cnt % 2){
        cout<<-1<<endl;
        return;
    }

    adj.assign(n,vector<pair<int,int>> ());
    vis.assign(n,0);
    parity.assign(n,0);
    used.assign(m,0);
    ok = true;

    forn(i,m){
        int u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }

    dfs(0,-1);

    vector<int> ans;
    forn(i,m){
        if(used[i]) ans.pb(i+1);
    }

    cout<<ans.size()<<endl;
    for(auto &x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
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
