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

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    
    vector<vector<int>> adj(n);
    vector<int> l(n,-1); 

    for(int i=0;i<n-k;i++){
        // case 1
        if(a[i]!=a[i+k]){
            l[i]=a[i]; // bi = ai
            l[i+k]=a[i+k]; // bi+k = ai+k
        }else{
            // case 2
            // b[i] == b[i+k] then 
            // connect i and i+k together
            adj[i].push_back(i+k);
            adj[i+k].push_back(i);
        }
    }

    // traversal conflicts
    vector<bool> vis(n,false);
    
    //bfs
    for(int i=0; i<n; i++){ 
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vector<int> c;
            vis[i]=true;
            int req=-1; // required value for this component if locked

            while(!q.empty()){
                int u=q.front();
                q.pop();
                c.push_back(u);
                
                // if this is locked
                if(l[u]!=-1){
                    if(req==-1) req=l[u];
                    else if(req!=l[u]){
                        //conflict
                        cout<<"NO\n";
                        return;
                    }
                }

                if(b[u]!=-1){
                    if(req==-1) req=b[u];
                    else if(req!=b[u]){
                        //conflict
                        cout<<"NO\n";
                        return;
                    }
                }

                for(int nbh:adj[u]){
                    if(!vis[nbh]){
                        vis[nbh]=true;
                        q.push(nbh);
                    }
                }
            }

            if(req!=-1){
                for(int j:c){
                    b[j]=req;
                }
            }
        }
    }

    // fill 
    vector<int> f(n+1,0);
    for(int i=0;i<k;i++){
        f[a[i]]++;
    }
    
    for(int i=0;i<k;i++){
        if(b[i]!=-1){
            f[b[i]]--;
            if(f[b[i]]<0){
                cout<<"NO\n";
                return;
            }
        }
    }

    cout<<"YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test;
    cin >> test; 
    while (test--) {
        solve();
    }
    return 0;
}