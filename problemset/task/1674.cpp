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

const int N=2e5+5;
vi g[N];
int sub[N];

void dfs(int u){
    for(auto v:g[u]){
        dfs(v);
        sub[u]+=sub[v]+1;

    }
}

void solve() {
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        g[i].clear();
        sub[i]=0;
    }

    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        g[p].pb(i);
    }
    dfs(1);

    for(int i=1;i<=n;i++){
        cout<<sub[i]<<" ";
    }
    cout<<endl;

    // Your code here
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