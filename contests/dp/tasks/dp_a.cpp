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
    int n;
    cin>>n;
    vi H(n);
    // H[i] stone height
    // from i can jump to i+1 or i+2
    // cost of jump is abs(H[i]-H[j])

    vector<int> dp(n,inf); // dp[i] minimum cost to reach stone i
    dp[0]=0;
    for(int i=0;i<n;i++){
        if(i+1<n){
            dp[i+1]=min(dp[i+1],dp[i]+abs(H[i]-H[i+1]));
        }
        if(i+2<n){
            dp[i+2]=min(dp[i+2],dp[i]+abs(H[i]-H[i+2]));
        }
    }
    cout<<dp[n-1]<<endl;
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