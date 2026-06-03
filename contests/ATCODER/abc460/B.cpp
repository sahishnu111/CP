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
    ll x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;

    ll d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    ll lower = (r1-r2)*(r1-r2);
    ll upper = (r1+r2)*(r1+r2);
    
    if(d < lower){
        cout<<"No"<<endl;
    }else if(d >= lower && d <= upper){ 
        cout<<"Yes"<<endl;
    }else if(d > upper){
        cout<<"No"<<endl;
    }
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