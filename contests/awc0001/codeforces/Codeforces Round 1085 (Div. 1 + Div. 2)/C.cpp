#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

vector<ll> bfs(int s, int n, const vector<ll>& a) {
    vector<ll> b(n, 0);
    queue<int> q;
    vector<int> vis(n, 0);

    q.push(s);
    vis[s] = 1;
    b[s] = a[s];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : {u - 1, u + 1}) {
            if (v >= 0 && v < n && !vis[v]) {
                vis[v] = 1;
                b[v] = max(b[u], a[v]);
                q.push(v);
            }
        }
    }
    return b;
}

void solve() {
    int n;
    ll h;
    cin >> n >> h;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> L(n);
    for (int i = 0; i < n; i++) {
        L[i] = bfs(i, n, a);
    }

    vector<vector<ll>> p(n, vector<ll>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j + 1] = p[i][j] + L[i][j];
        }
    }

    ll mn = 4e18;

    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i; j < n; j++) {

            if (a[j] > a[k]) k = j;

            ll cur = p[i][k + 1] + (p[j][n] - p[j][k + 1]);
            mn = min(mn, cur);
        }
    }

    ll tt = n * h;
    cout << tt - mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}