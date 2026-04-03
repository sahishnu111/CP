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
#define inf 1e9
#define INF 1e18

void solve() {
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    // ai equals 0, if on the i-th day of vacations the gym is closed and the contest is not carried out;
    // ai equals 1, if on the i-th day of vacations the gym is closed, but the contest is carried out;
    // ai equals 2, if on the i-th day of vacations the gym is open and the contest is not carried out;
    // ai equals 3, if on the i-th day of vacations the gym is open and the contest is carried out.
    // do the same activity on two consecutive days

    //minimum possible number of days on which Vasya will have a rest

    // we will do dp
    vector<vector<int>> dp(n+1,vector<int>(3,inf)); // dp[i][j] = minimum rest days up to day i if we do activity j on day i (0-rest, 1-contest, 2-gym)
    
    dp[0][0]=0; 

    for(int i=1;i<=n;i++){
        // opt 0 
        dp[i][0]=1+min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}); // rest today, so add 1 to the minimum of yesterday's activities
        if(a[i-1]==1 || a[i-1]==3){
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]); // contest today, so we can only come from rest or gym yesterday

        }
        if(a[i-1]==2 || a[i-1]==3){
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]); // gym today, so we can only come from rest or contest yesterday
        }

    }

    cout<<min({dp[n][0],dp[n][1],dp[n][2]})<<endl; // minimum rest days up to day n

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