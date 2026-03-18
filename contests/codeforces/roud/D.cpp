#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define endl '\n'

vector<int> adj[200005];
int color[200005]; // -1 unvist , 0 1

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        color[i] = -1; 
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll ans = 0;
    

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            int t1 = 0, t2 = 0;
            bool bipart = true;

            queue<int> q;
            q.push(i);
            color[i] = 0;
            t1++;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        if (color[v] == 0) t1++;
                        else t2++;
                        q.push(v);
                    } 
                    else if (color[v] == color[u]) {
                        bipart = false;
                    }
                }
            }

            if (bipart) {
                ans += max(t1, t2);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}