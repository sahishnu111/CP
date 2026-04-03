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
const ll INF = 1e18; 

int countFAC(int x, int p) {
    if (x == 0) return 1; // Special case: treat 0 as having 1 factor to get 1 trailing zero
    int cnt = 0;
    while (x > 0 && x % p == 0) {
        cnt++;
        x /= p;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    bool hasZero = false;
    int zeroR = -1, zeroC = -1;
    vector<vector<int>> grid(n, vector<int>(n));
    forn(i, n) {
        forn(j, n) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) {
                hasZero = true;
                zeroR = i;
                zeroC = j;
            }
        }
    }

    
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 1e9)));
    vector<vector<vector<int>>> parent(n, vector<vector<int>>(n, vector<int>(2, -1))); 

    for (int pidx = 0; pidx < 2; pidx++) {
        int p = (pidx == 0) ? 2 : 5;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int fact = countFAC(grid[i][j], p);
                if (i == 0 && j == 0) {
                    dp[i][j][pidx] = fact;
                } else if (i == 0) {
                    dp[i][j][pidx] = fact + dp[i][j - 1][pidx];
                    parent[i][j][pidx] = 1; // Must come from Left (Right move)
                } else if (j == 0) {
                    dp[i][j][pidx] = fact + dp[i - 1][j][pidx];
                    parent[i][j][pidx] = 0; // Must come from Top (Down move)
                } else {
                    if (dp[i - 1][j][pidx] < dp[i][j - 1][pidx]) {
                        dp[i][j][pidx] = fact + dp[i - 1][j][pidx];
                        parent[i][j][pidx] = 0; // Down
                    } else {
                        dp[i][j][pidx] = fact + dp[i][j - 1][pidx];
                        parent[i][j][pidx] = 1; // Right
                    }
                }
            }
        }
    }

    int res2 = dp[n - 1][n - 1][0];
    int res5 = dp[n - 1][n - 1][1];
    int best = min(res2, res5);

    // If zero exists and best path is "rounder" than 1 zero, take the zero path
    if (hasZero && best > 1) {
        cout << "1" << endl;
        string zPath = "";
        for (int i = 0; i < zeroR; i++) zPath += "D";
        for (int j = 0; j < zeroC; j++) zPath += "R";
        for (int i = zeroR; i < n - 1; i++) zPath += "D";
        for (int j = zeroC; j < n - 1; j++) zPath += "R";
        cout << zPath << endl;
        return;
    }

    cout << best << endl;
    int bestRes = (res2 < res5) ? 0 : 1;

    string path = "";
    int i = n - 1, j = n - 1;
    while (i > 0 || j > 0) {
        if (parent[i][j][bestRes] == 0) {
            path += 'D';
            i--;
        } else {
            path += 'R';
            j--;
        }
    }

    reverse(all(path));
    cout << path << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}