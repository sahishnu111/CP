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

/*
We are given an Array of Numbers. We have to find and print any Number with Maximum Frequency and Minimum Frequency.

Example Testcase:-

Arr = [3, 2, 3, 2, 4, 3]

Frequencies of Elements of Array are:-

3 - 3
2 - 2
4 - 1

Maximum Frequency:- Element is 3, Frequency is 3
Minimum Frequency:- Element is 4, Frequency is 1

*/

void solve() {
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    
    unordered_map<int,int> m;
    for(auto x : a) m[x]++;

    int mxf = 0, mnf = n + 1, mxE = a[0], mnE = a[0];
    for(auto &[k, v] : m) {
        if(v > mxf) mxf = v, mxE = k;
        if(v < mnf) mnf = v, mnE = k;
    }
    cout << "Maximum Frequency:- Element is " << mxE << ", Frequency is " << mxf << endl;
    cout << "Minimum Frequency:- Element is " << mnE << ", Frequency is " << mnf << endl;
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