#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)

const vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

pair<int,int> dfs(int x,int y,const vector<vector<char>> &grid,
                  vector<vector<bool>> &visited,const int n,const int m,
                  bool &escape){
    if(x<0 || y<0 || x>=n || y>=m) return {0,0};
    if(visited[x][y] || grid[x][y]== '#') return {0,0};

    visited[x][y]=true;

    // If we reach boundary, escape is possible
    if(x==0 || y==0 || x==n-1 || y==m-1) escape = true;

    int sheeps = 0, wolves = 0;

    if(grid[x][y]=='k') sheeps++;
    else if(grid[x][y]=='v') wolves++;

    for(auto d:directions){
        int X= x+d.first;
        int Y= y+d.second;
        if(X<0 || Y<0 || X>=n || Y>=m) continue;   
        if(visited[X][Y] || grid[X][Y]=='#') continue;

        pair<int,int> temp = dfs(X,Y,grid,visited,n,m,escape);
        sheeps += temp.first;
        wolves += temp.second;
    }

    return {sheeps, wolves};
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));

    forn(i,n){
        forn(j,m){
            cin>>grid[i][j];
        }
    }

    vector<vector<bool>> visited(n,vector<bool>(m,false));

    int totalSheeps=0;
    int totalWolves=0;

    forn(i,n){
        forn(j,m){
            if(visited[i][j] || grid[i][j]== '#') continue;

            bool escape = false;
            pair<int,int> res = dfs(i,j,grid,visited,n,m,escape);

            int sheeps = res.first;
            int wolves = res.second;

            if(escape){
                // all survive
                totalSheeps += sheeps;
                totalWolves += wolves;
            }
            else{
                // fight
                if(sheeps > wolves) totalSheeps += sheeps;
                else totalWolves += wolves;
            }
        }
    }

    cout<<totalSheeps<<" "<<totalWolves<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
