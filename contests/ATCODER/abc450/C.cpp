#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool bfs(vector<vector<char>> &grid, int X,int Y){
    queue<pair<int,int>> q;
    q.push({X,Y});
    grid[X][Y]='#';
    bool c = true;
    
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        if(x == 0 || x == grid.size()-1 || y == 0 || y == grid[0].size()-1){
            c = false;
        }

        for(auto d : dir){
            int nx = x + d[0];
            int ny = y + d[1];

            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()){
                if(grid[nx][ny] == '.'){
                    grid[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }
    }

    return c; 
}

void solve() {
    int H,W;
    cin>>H>>W;

    vector<vector<char>> grid(H, vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>grid[i][j];
        }
    }

    int cnt=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(grid[i][j]=='.'){
                if(bfs(grid,i,j)){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}