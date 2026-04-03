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

vll pw, mul,gd;

void dfs(ll curr){
    for(size_t i=0;i<pw.size();i++){
        ll p=pw[i];
        ll m=mul[i];

        // shift to cuur to next p and add p
        ll n=(curr*m)+p;

        // stop 
        if(n<=1000000000LL){
            gd.push_back(n);
            dfs(n);
        }
    }
}

void solve() {

    // pre compute 
    ll p=1;
    while(p<=1000000000LL){
        pw.push_back(p);
        string s=to_string(p);
        ll m=1;
        for(char c:s){
            m*=10; // shift 
        }

        mul.push_back(m);
        p*=2;
    }




    int n;
    cin>>n;

    dfs(0);

    sort(all(gd));
    gd.erase(unique(all(gd)),gd.end()); // remove duplicates

    cout<<gd[n-1]<<endl;
    
    
    
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