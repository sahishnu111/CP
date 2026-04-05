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
    int h,w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0 || i==h-1 || j==0 || j==w-1) grid[i][j] = '#';
            else grid[i][j] = '.'; 
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

    
    
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