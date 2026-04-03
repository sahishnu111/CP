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
    map<char, int> colorCnt; 
    colorCnt['R'] = 0;
    colorCnt['G'] = 0;
    colorCnt['B'] = 0;
    cin >> colorCnt['R'] >> colorCnt['G'] >> colorCnt['B'];
    
    string s = "";
    
    while (true) {
        char bs = ' ';
        int mx = -1;
        
        for (char c : {'R', 'G', 'B'}) {
            if (colorCnt[c] == 0) continue;
            
            if (s.size() >= 1 && s.back() == c) continue;
            
            if (s.size() >= 3 && s[s.size() - 3] == c) continue;
            
            int score = colorCnt[c] * 10;
            
            if (s.size() >= 2 && s[s.size() - 2] == c) {
                score += 1;
            }
            
            if (score > mx) {
                mx = score;
                bs = c;
            }
        }
        
        if (bs == ' ') break;
        
        s += bs;
        colorCnt[bs]--; 
    }
    
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}