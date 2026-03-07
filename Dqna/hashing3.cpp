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


//Count all the (i,j) Pairs such that b[i] + b[j] == k (count of such pairs.) [i<j] 

void solve() {
    // b[i] + b[j] == k => b[j] == k - b[i]
    // For each j, check how many previous i have a[i] == k - a[j]
    int n, k;
    cin >> n >> k;
    vi a(n);
    forn(i, n) cin >> a[i];
    unordered_map<int, int> m;
    ll pairs = 0;
    forn(i, n) {
        if (m.count(k - a[i])) pairs += m[k - a[i]];
        m[a[i]]++;
    }
    cout << pairs << endl;
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