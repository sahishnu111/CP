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


long long cntLess(vector<ll> &a, ll x){
    // cnt sum <= x
    int n=a.size();
    long long cnt=0;
    int l=0;
    int r=n-1;
    while(l<r){
        if(a[l]+a[r]<=x){
            cnt+=(r-l);
            l++;
        }
        else{
            r--;
        }
    }

    return cnt;
}



void solve() {
    int n;
    ll x,y;
    cin>> n >> x >> y;
    vll a(n);
    forn(i,n) cin>> a[i];
    ll S=0;
    forn(i,n) S+=a[i];

    ll lw=S-y;
    ll up=S-x;

    

    sort(a.begin(), a.end());
    
    cout << cntLess(a, up) - cntLess(a, lw - 1) << endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}