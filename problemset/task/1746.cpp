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

void ArrayDescription() {
    int n,m;
    cin>>n>>m;
    vi a(n);
    forn(i,n) cin>>a[i];
    
    // we have an array btweern 1 to m value each element
    // if array element is 0 we can replace it with any value between 1 to m
    // if elemet is 0 we can replace it with any value between 1 to m
    // adjacent elements must be at most 1 difference
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    
    if(a[0]==0){
        for(int j=1;j<=m;j++) dp[0][j]=1;
    }else{
        dp[0][a[0]]=1;
    }

    for(int i=1;i<n;i++){
        if(a[i]==0){
            for(int j=1;j<=m;j++){
                for(int prev:{j-1,j,j+1}){
                    if(prev>=1 && prev<=m){
                        dp[i][j]=(dp[i][j]+dp[i-1][prev])%mod;
                    }
                }
            }
        }else{
            int j=a[i];
            for(int prev:{j-1,j,j+1}){
                if(prev>=1 && prev<=m){
                    dp[i][j]=(dp[i][j]+dp[i-1][prev])%mod;
                }
            }
        }
    }


    int ans=0;
    for(int j=1;j<=m;j++) ans=(ans+dp[n-1][j])%mod;
    cout<<ans<<endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        ArrayDescription();
    }
    return 0;
}