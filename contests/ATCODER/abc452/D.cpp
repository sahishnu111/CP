#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int n = S.size();
    int m = T.size();

    vector<vector<int>> nxt(n + 2, vector<int>(26, n));

    for (int c = 0; c < 26; c++) nxt[n][c] = n;

    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][S[i] - 'a'] = i;
    }

    ll total = 1LL * n * (n + 1) / 2;
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        int p = i;
        bool t = true;

        for (int j = 0; j < m; j++) {
            if (p >= n) {
                t = false;
                break;
            }
            p = nxt[p][T[j] - 'a'];
            if (p == n) {
                t = false;
                break;
            }
            p++;
        }

        if (t) {
            int end = p - 1;
            cnt += (n - end);
        }
    }

    cout << total - cnt << '\n';
    return 0;
}