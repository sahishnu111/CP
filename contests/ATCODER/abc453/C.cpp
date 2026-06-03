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
    int x;
    cin >> x;
    vll a(x);
    forn(i, x) cin >> a[i];

    // 0.5 on a number line.
    //  he chooses either the positive direction or the negative direction, and moves ai units in that direction.
    // maximum number of times he can pass through coordinate 0
    // we can pass through 0 if we move in the negative direction and then in the positive direction or vice versa
    // we will use dp

    vector<map<ll,int>> dp(x+1);
    // dp[i] stores {pos , max crosses} after move i


    dp[0][1] = 0; 

    for(int i=0;i<x;i++){
        ll d=a[i]*2;
        for(auto const &[pos, dx] : dp[i]){

            // move positive
            ll nxt1 = pos + d;  
            int cx1 = ((pos > 0 && nxt1 < 0) || (pos < 0 && nxt1 > 0)) ? 1 : 0;
            dp[i+1][nxt1] = max(dp[i+1][nxt1], dx + cx1);

            // move negative
            ll nxt2 = pos - d;  
            int cx2 = ((pos > 0 && nxt2 < 0) || (pos < 0 && nxt2 > 0)) ? 1 : 0;
            dp[i+1][nxt2] = max(dp[i+1][nxt2], dx + cx2);

        }
    }



    int ans = 0;
    for(auto const &[pos, dx] : dp[x]){
        ans = max(ans, dx);
    }

    cout << ans << endl;

    
    
    
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