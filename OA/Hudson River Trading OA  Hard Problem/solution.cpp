#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define F first
#define S second
#define vll vector<ll>

void solve() {
    int n; // grid dimension
    cin >> n;
    
    int m; // You need to declare and read 'm' (number of crops)
    cin >> m;
    
    vector<vector<pair<int, ll>>> cols(n);
    for (int i = 0; i < m; ++i) {
        int r, c;
        ll val = 1; 
        cin >> r >> c >> val; 
        cols[c].push_back({r, val});
    }

    // --- REMOVED THE OLD 2D DP AND GRID CODE HERE ---

    vector<ll> ans(n, 0);
    vll dp(n+1, 0); // 1D DP array

    // left to right column by column
    for(int c=0; c<n; c++){
        ans[c] += dp[n];

        // prefix sum for our current column
        vll S(n+1, 0);
        for(auto &p : cols[c]){
            S[p.F+1] += p.S; 
        }
        for(int h=1; h<=n; h++){
            S[h] += S[h-1]; 
        }

        // dp for next column
        vll DP(n+1, 0);
        ll mx = dp[0] - S[0];
        // CHANGED 'k' to 'n'
        for(int h=0; h<=n; h++){ 
            mx = max(mx, dp[h] - S[h]);
            DP[h] = S[h] + mx;
        }
        dp = DP;
    }

    // right to left
    dp.assign(n+1, 0);
    for(int x=n-1; x>=0; x--){
        ans[x] += dp[n];

        vll S(n+1, 0);
        for(auto &p : cols[x]){
            S[p.F+1] += p.S; 
        }
        for(int h=1; h<=n; h++){
            S[h] += S[h-1]; 
        }

        vll DP(n+1, 0);
        ll mx = dp[0] - S[0];
        // CHANGED 'k' to 'n'
        for(int h=0; h<=n; h++){ 
            mx = max(mx, dp[h] - S[h]);
            DP[h] = S[h] + mx;
        }
        dp = DP;
    }

    // find global max
    ll MX = 0;
    for(int i=0; i<n; i++){
        MX = max(MX, ans[i]);
    }

    cout << MX << endl;
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