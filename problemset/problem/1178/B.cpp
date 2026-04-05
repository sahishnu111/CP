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
    string s; 
    cin >> s;
    int n = s.size();
    
    ll totalW = 0;
    for(int i = 1; i < n; i++) {
        if(s[i-1] == 'v' && s[i] == 'v') totalW++;
    }
    
    ll sumO = 0;
    ll cntX = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == 'v' && s[i-1] == 'v') {
            cntX++;
        }
        else if(s[i] == 'o') {
            sumO += ((totalW - cntX) * cntX);
        }
    }
    cout << sumO << endl;
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