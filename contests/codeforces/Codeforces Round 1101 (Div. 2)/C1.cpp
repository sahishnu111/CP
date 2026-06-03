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
    int n,x,s;
    cin >> n >> x >> s;
    string u;
    cin >> u;

    vector<int> dp(x+1, -1); 
    dp[x] = 0; // base case

    forn(i,n){
        char c= u[i];

        for(int E=0;E<=x;E++){
            if(dp[E] == -1) continue;

            int p=dp[E]; // people table
            int v= (x-E)*s-p; // people ava

            //sit at empty table 
            if((c=='I' || c=='A' )&& E>0){
                // intro and amvi
                dp[E-1]=max(dp[E-1],(int)(p+1));
            }

            //sit at non empty table
            if((c=='E' || c=='A') && v>0){
                // extro and amvi
                dp[E]=max(dp[E],(int)(p+1)); 
            }

        }
    }

    int mx=0;
    for(int E=0;E<=x;E++){
        if(dp[E]>mx) mx=dp[E];
    }

    cout<<mx<<endl;

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