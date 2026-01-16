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

vector<pair<int,int>> dxr={{0,1},{1,0},{0,-1},{-1,0}};

int dfs(int x,int y,const vector<vector<char>> & grid,vector<vector<bool>> &visited,const int n,const int m){
    if(x<0 || y<0 || x>=n || y>=m ) return 0;
    if(visited[x][y] || grid[x][y]== '~' ) return 0;

    visited[x][y]=true;
    int c=1; // atleast 1 cell (itself)

    for(auto d:dxr){
        int X= x+d.first;
        int Y= y+d.second;
        if(X<0 || Y<0 || X>=n || Y>=m) continue;   
        if(visited[X][Y] || grid[X][Y]=='~') continue;
        c+=dfs(X,Y,grid,visited,n,m);
    }
    return c;
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
    
    // we will find the size of all the components of land cells
    long long cmp=0;   

    forn(i,n){
        forn(j,m){
            if(visited[i][j] || grid[i][j]=='~') continue;
            int sz=dfs(i,j,grid,visited,n,m);
            cmp+=(1LL*sz*sz);
        }
    }

    long long total = 1LL*n*m;
    long long g=__gcd(cmp,total);

    if(total/g == 1){
        cout<<cmp/total<<endl;
    }else{
        cout<<cmp/g<<" / "<<total/g<<endl;
    }
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
