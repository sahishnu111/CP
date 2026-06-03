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
    double ans=0;
    vi die={4,5,6};
    vvi cnt(3,vi(7,0));
    forn(i,3){
        forn(j,6){
            int x;
            cin >> x;
            cnt[i][x]++;
        }
    }
    double p=0;
    do{
        p+=cnt[0][die[0]]*cnt[1][die[1]]*cnt[2][die[2]];

    }while(next_permutation(die.begin(),die.end())); 

    ans=p/216.0;
    cout<<fixed<<setprecision(6)<<ans<<endl;
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