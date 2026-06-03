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

struct Color {
    char black = '#';
    char white = '.';
    int db = -1;//unvisi
    int dw = -1; //unvisi
};

void solve() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    forn(i,h) cin>>s[i];
    
    vector<vector<Color>> grid(h, vector<Color>(w)); 
    queue<pair<int,int>> qb, qw;
    bool bl=false,wh=false;
    
    forn(i,h){
        forn(j,w){
            if(s[i][j]=='#'){
                grid[i][j].db = 0; 
                qb.push({i,j});
                bl=true;
            } 
            else {
                grid[i][j].dw = 0;
                qw.push({i,j});
                wh=true;
            }
        }
    }

    if(!bl || !wh){
        forn(i,h) cout<<string(w,'.')<<endl; 
        return;
    }

    vector<pair<int,int>> dxn = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};

    while(!qb.empty()){
        auto [x,y] = qb.front();
        qb.pop();
        for(auto [dx,dy]:dxn){
            int nx = x+dx;
            int ny = y+dy;
            if(nx>=0 && nx<h && ny>=0 && ny<w){
                if(grid[nx][ny].db == -1){ 
                    grid[nx][ny].db = grid[x][y].db + 1; 
                    qb.push({nx,ny});
                }
            }
        }
    }

    while(!qw.empty()){
        auto [x,y] = qw.front();
        qw.pop();
        for(auto [dx,dy]:dxn){
            int nx = x+dx;
            int ny = y+dy;
            if(nx>=0 && nx<h && ny>=0 && ny<w){
                if(grid[nx][ny].dw == -1){ 
                    grid[nx][ny].dw = grid[x][y].dw + 1; 
                    qw.push({nx,ny});
                }
            }
        }
    }

    forn(i,h){
        forn(j,w){
            if(s[i][j] == '.') {
                if(grid[i][j].db % 2 == 0) cout << grid[i][j].black;
                else cout << grid[i][j].white;
            } else {
                if(grid[i][j].dw % 2 != 0) cout << grid[i][j].black;
                else cout << grid[i][j].white;
            }
        }
        cout<<endl;
    }
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