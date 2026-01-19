#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> drx = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x, int y, vector<vector<char>> &grid,
         vector<vector<bool>> &visited, int n, int m) {

    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (visited[x][y] || grid[x][y] == '#') return;

    visited[x][y] = true;

    for (auto d : drx) {
        dfs(x + d[0], y + d[1], grid, visited, n, m);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, grid, visited, n, m);
                rooms++;
            }
        }
    }

    cout << rooms << '\n';
    return 0;
}
