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
#define mod 998244353
#define inf 1e18

void solve() {
    ll m,n;
    cin>>n>>m;

    ll ans=0;
    ll p1=1;
    ll KM=0;

    int l = to_string(n).size();

    for(int i=1;i<=l;i++){
        KM = (KM*10 + 9) % m;
        ll mny = p1;
        ll mxy = (i==19) ? n: min(n, p1*10-1);
        ll cnty = max(0LL, mxy-mny+1);



        ll r = m / std::gcd(m,KM); 
        ll cntx = n/r;
        cnty %= mod;
        cntx %= mod;



        ans = (ans + cntx*cnty) % mod;
        if (i<19) p1 *= 10;
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    cin>>test;
    while (test--) {
        solve();
    }
    return 0;
}