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

void GridPathsI() {
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    forn(i, n){ forn(j, n) cin>>grid[i][j]; }

    //number of path from (0,0) to (n-1,n-1) moving only right and down
    vector<vector<int>> dp(n,vector<int>(n,0));
    if(grid[0][0]=='*') return void(cout<<0<<endl); // if starting point is blocked, no paths
    dp[0][0]=1; // base case
    forn(i,n){
        forn(j,n){
            if(i==0 && j==0) continue;
            if(grid[i][j]=='*') dp[i][j]=0; //blocked 
            else{
                if(i>0) dp[i][j]+=dp[i-1][j]; // from top
                if(j>0) dp[i][j]+=dp[i][j-1]; // from left
                dp[i][j]%=mod; // to avoid overflow
            }
        }
    }


    cout<<dp[n-1][n-1]<<endl;


    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    //cin >> test;
    while (test--) {
        GridPathsI();
    }
    return 0;
}