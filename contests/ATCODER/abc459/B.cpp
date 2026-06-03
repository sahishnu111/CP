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
    // hashmap 
    int n;
    cin >> n;
    vector<string> words(n);
    forn(i, n) cin >> words[i];
    
    map<char,int> f={
        {'a',2},{'b',2},{'c',2},
        {'d',3},{'e',3},{'f',3},
        {'g',4},{'h',4},{'i',4},
        {'j',5},{'k',5},{'l',5},
        {'m',6},{'n',6},{'o',6},
        {'p',7},{'q',7},{'r',7},{'s',7},
        {'t',8},{'u',8},{'v',8},
        {'w',9},{'x',9},{'y',9},{'z',9}
    };

    
    string ans;
    for(const auto &word: words){
        char c = word[0];
        ans+= to_string(f[c]);

    }

    cout << ans << endl;
    
    
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