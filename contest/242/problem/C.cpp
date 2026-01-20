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

void solve() {
    // Your code here
    int intialX,intialY,finalX,finalY;
    cin>>intialX>>intialY>>finalX>>finalY;

    int n;
    cin>>n;

    //vector<vector<tuple<int,int,int>>> moves(n,vector<tuple<int,int,int>>());
    // hashmap of (a,b) (a,b+1) ... (a,r);
    unordered_map<int,vector<pii>> rowMoves;
    unordered_map<int,vector<pii>> colMoves;
    set<pii> allowedCells;
    forn(i,n){
        int r,a,b;
        cin>>r>>a>>b;
        for(int j=a;j<=b;j++){
            //moves[i].pb({r,j,0});
            rowMoves[r].pb({r,j});
            colMoves[j].pb({r,j});
            allowedCells.insert({r,j});
        }
    }

    //bfs
    queue<pair<int,int>> q;
    q.push({intialX,intialY});

    map<pii,bool> visited;
    visited[{intialX,intialY}]=true;
    int pathLength=0;
    //(x±1, y), (x, y±1), (x±1, y±1)
    vector<pii> directions={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    map<pii,int> dist;
    dist[{intialX,intialY}]=0;

    bool pathFound=false;

    while(!q.empty()){
        auto [x,y] =q.front();
        q.pop();
        
        if(x==finalX && y==finalY){
            pathFound=true;
            pathLength=dist[{x,y}];
            break;
        }
        
        for(auto [dx,dy] : directions){
            int X=x+dx;
            int Y=y+dy;
            if(visited.find({X,Y})==visited.end()){
                if(allowedCells.find({X,Y})!=allowedCells.end()){
                    visited[{X,Y}]=true;
                    q.push({X,Y});
                    dist[{X,Y}]=dist[{x,y}]+1;
                }
            }
        }
    }

    if(pathFound){
        cout<<pathLength<<endl;
    }else{
        cout<<-1<<endl;
    }   
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
