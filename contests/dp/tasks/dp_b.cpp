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
    int n,k;
    cin>>n>>k;
    vi H(n);
    forn (i,n) cin>>H[i];
    
    vector<long long> dp(n, (long long)inf); 
    dp[0]=0;
    for(int i=0;i<n;i++){
        if(dp[i]==(long long)inf) continue;
        for(int j=1;j<=k;j++){
            if(i+j<n){
                dp[i+j]=min(dp[i+j],dp[i]+abs(H[i]-H[i+j]));
            }
        }
    }
    cout<<dp[n-1]<<endl;
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
