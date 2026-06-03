#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)x.size()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define mod 1000000007
#define inf 1e18

struct node{
    int x,y,dir;
};

struct Parent{
    int px,py,pdir;
    char c; 
};

Parent p[1005][1005][5];
bool visited[1005][1005][5];

void addPath(string &path, int dir){
    if(dir == 0) path += 'U';
    else if(dir == 1) path += 'D';
    else if(dir == 2) path += 'L';
    else if(dir == 3) path += 'R';
}

void solve() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    pair<int,int> start, end;
    forn(i,h) forn(j,w){
        cin >> grid[i][j];
        if(grid[i][j] == 'S') start = {i,j};
        if(grid[i][j] == 'G') end = {i,j};
    }

    //If Si,j​=#: This cell cannot be entered.
    //If Si,j​=.: This cell can be freely entered and exited. That is, after entering this cell, Takahashi can move to any adjacent cell (if it exists) in the up, down, left, or right direction.
    //If Si,j​=o: In this cell, Takahashi must move in the same direction as the immediately preceding move. That is, after entering this cell, he must move to the next cell without changing direction.
    //If Si,j​=x: In this cell, Takahashi cannot move in the same direction as the immediately preceding move. That is, after entering this cell, he must change direction to move to the next cell. Turning 180 degrees to return to the previous cell is considered as changing direction.
    //If Si,j​=S: This cell is Takahashi's starting position. This cell can be freely entered and exited.
    //If Si,j​=G: This cell is Takahashi's destination. This cell can be freely entered and exited.

    // we will do bfs from S to G with at most 5*1e6 moves
    vector<vector<int>> dxr = {{-1,0},{1,0},{0,-1},{0,1}}; // up down left right
    char dirc[] = {'U','D','L','R'};
    queue<node> q; // {x,y,dir,path}

    q.push({start.F, start.S, 4}); // dir 4 means no previous moves
    visited[start.F][start.S][4] = true;

    while(!q.empty()){
        node curr = q.front();
        q.pop();
        
        if(curr.x == end.F && curr.y == end.S){
            string pt="";
            node t=curr;
            while(!(t.x==start.F && t.y==start.S && t.dir==4)){
                Parent par = p[t.x][t.y][t.dir];
                pt+=par.c;
                t={par.px, par.py, par.pdir};
            }
            reverse(all(pt));
            cout << "Yes" << endl;
            cout << pt << endl;
            return;
        }


        char cell = grid[curr.x][curr.y];

        for(int i=0;i<4;i++){
            if(cell == 'o' && curr.dir!=4 && i!= curr.dir) continue; // must move in the same direction
            if(cell == 'x' && curr.dir!=4 && i== curr.dir) continue; // must change direction
            int nx= curr.x + dxr[i][0];
            int ny= curr.y + dxr[i][1];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue; // out of bounds
            if(grid[nx][ny] == '#') continue; // cannot enter
            if(!visited[nx][ny][i]){
                visited[nx][ny][i] = true;
                p[nx][ny][i] = {curr.x, curr.y, curr.dir, dirc[i]};
                q.push({nx, ny, i});
            }
        }
        

    }
    cout << "No" << endl;

    
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        solve();
    }
    return 0;
}