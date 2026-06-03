
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
//You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
    int n,x;
    cin>>n>>x;
    vi a(n);
    forn(i,n) cin>>a[i];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int need = x - a[i];
        if(mp.count(need)){
            cout<<mp[need]+1<<" "<<i+1<<endl;
            return;
        }
        mp[a[i]] = i;
    }
    cout<<"IMPOSSIBLE"<<endl;
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