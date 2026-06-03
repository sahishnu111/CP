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

    vector<vector<string>> grid(h, vector<string>(w));

    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++){
            grid[i][j] = s[j];
        }
    }

    int ans = 0;

    for(int h1=0;h1<h;h1++){
        for(int h2=h1;h2<h;h2++){
            for(int w1=0;w1<w;w1++){
                for(int w2=w1;w2<w;w2++){

                    bool sym=true;

                    for(int i=h1;i<=h2;i++){
                        for(int j=w1;j<=w2;j++){
                            if(grid[i][j] != grid[h1+h2-i][w1+w2-j]){
                                sym=false;
                                break;
                            }
                        }
                        if(!sym) break;
                    }

                    if(sym) ans++;
                }
            }
        }
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