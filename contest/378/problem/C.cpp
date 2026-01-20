#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int n, m, k;
vector<vector<char>> maze;
vector<vector<bool>> vis;

vector<pii> directions = {
    {-1, 0}, {0, -1}, {0, 1}, {1, 0}
};

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (vis[x][y] || maze[x][y] == '#')
        return;

    vis[x][y] = true;

    for (auto [dx, dy] : directions) {
        dfs(x + dx, y + dy);
    }

    // post-order removal
    if (k > 0) {
        maze[x][y] = 'X';
        k--;
    }
}

void solve() {
    cin >> n >> m >> k;

    maze.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    // start DFS from the first empty cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                dfs(i, j);
                i = n;  // break both loops
                break;
            }
        }
    }

    // output result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << maze[i][j];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
