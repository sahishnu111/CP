#include <bits/stdc++.h>
using namespace std;

bool cq(int L, int R, const string &s) {
    int cur = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (i >= L && i <= R) continue;
        cur += (s[i] == '(' ? 1 : -1);
        if (cur < 0) return false;
    }
    return true;
}

void solve() {
    int n; string s;
    cin >> n >> s;

    int bal = 0;
    vector<int> pref(n);

    for (int i = 0; i < n; i++) {
        bal += (s[i] == '(' ? 1 : -1);
        pref[i] = bal;
    }

    if (bal != 0) {
        cout << "NO\n";
        return;
    }

    int l = 0;
    while (l < n && pref[l] >= 0) l++;

    if (l == n) {
        cout << "YES\n";
        return;
    }

    int r = n - 1;
    while (r >= 0 && pref[r] >= 0) r--;

    cout << (cq(l, r, s) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) solve();
}