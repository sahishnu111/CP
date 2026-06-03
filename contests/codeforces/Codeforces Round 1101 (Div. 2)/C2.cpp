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
    ll n, X, s;
    cin >> n >> X >> s;
    string u;
    cin >> u;
    
    long long HS = 0;
    long long seat = 0;

    vector<int> stk; 

    for (int i = 0; i < n; i++) {
        char c = u[i];

        if (c == 'I') {
            if (X > 0) {
                X--;
                HS += (s - 1);
                seat++;
            }
        } 
        else if (c == 'A') {
            if (HS > 0) {
                HS--;
                stk.push_back(i);
                seat++;
            } 
            else if (X > 0) {
                X--;
                HS += (s - 1);
                seat++;
            }
        } 
        else if (c == 'E') {
            if (HS > 0) {
                HS--;
                seat++;
            } 
            else if (!stk.empty() && X > 0) {
                stk.pop_back(); 
                X--;
                HS += (s - 1); 
                seat++;
            }
        }
    }

    cout << seat << "\n";
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