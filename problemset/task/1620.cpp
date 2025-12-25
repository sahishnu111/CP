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

bool canSat(const vll &num,ll x,const ll &t){
    ll sum=0;
    for(ll i=0;i<num.size();i++){
        sum+=(x/num[i]);
        if(sum>=t) return true;
    }

    return false;
}

void solve() {
    // Your code here
    int n,t;
    cin>>n>>t;
    vll A(n,0);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    ll l=0;
    ll h=1e18+1;
    while(h>l){
        ll m=l+(h-l)/2;
        if(canSat(A,m,t)){
            h=m;
        }else{
            l=m+1;
        }
    }

    cout<<l<<endl;
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