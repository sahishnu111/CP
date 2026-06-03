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
    int n,m;
    cin >> n >> m;
    int sum = 0;

    map<int , ll> cnt;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]+= x;
        sum+=x;
    }

    vector <ll> st;
    for(const auto& pair : cnt) {
        st.push_back(pair.second);
    }

    sort(all(st), greater<ll>());

    int mn = min((int)st.size(), k);
    ll t=0;
    for(int i=0;i<mn;i++){
         t+=st[i];
    }

    cout << sum-t << endl;    
    
    
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