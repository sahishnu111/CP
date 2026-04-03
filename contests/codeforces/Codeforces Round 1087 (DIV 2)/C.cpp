#include <bits/stdc++.h>
using namespace std;

int q(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

int qans() {
    vector<pair<int,int>> v = {{1,2}, {2,3}, {1,3}};
    for (int i = 0; i < 3; i++) {
        if (q(v[i].first, v[i].second) == 1) {
            return v[i].first;
        }
    }
    return -1;
}

int point(int n) {
    vector<pair<int,int>> v;
    for (int i = 4; i < 2 * n; i += 2) {
        v.push_back({i, i + 1});
    }

    for (auto &p : v) {
        if (q(p.first, p.second) == 1) {
            return p.first;
        }
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;

    int ans = qans();
    if (ans != -1) {
        cout << "! " << ans << endl;
        return;
    }

    ans = point(n);
    if (ans != -1) {
        cout << "! " << ans << endl;
        return;
    }

    cout << "! " << 2 * n << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}