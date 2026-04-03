#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n + 1);
    vector<int> l(k + 1), s(k + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> l[i];
    for (int i = 1; i <= k; i++) cin >> s[i];

    // dp[i][j]: i is the position of Handler A, j is the position of Handler B
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

    //base Case: Dono handlers start abhhi tak nahi 
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] == INF) continue;

            int st = max(i, j) + 1;
            if (st > n) continue;

            int type = a[st];

            //case 1
            int A;
            if (i == 0) A = l[type]; //first task for A
            else A = (a[i] == type) ? s[type] : l[type];

            dp[st][j] = min(dp[st][j], dp[i][j] + A);

            //case 2
            int B;
            if (j == 0) B = l[type]; 
            else B = (a[j] == type) ? s[type] : l[type];
            
            dp[i][st] = min(dp[i][st], dp[i][j] + B);
        }
    }

    int ans = INF;
    for (int i = 0; i <= n; i++) {
        ans = min({ans, dp[n][i], dp[i][n]});
    }

    cout << ans << endl;

    return 0;
}