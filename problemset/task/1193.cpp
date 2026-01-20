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

vector<pii> directions={{1,0},{-1,0},{0,1},{0,-1}};






void solve() {
    // Your code here
    int n,m;
    cin>>n>>m;
    pair<int,int> start,end;
    vector<vector<char>> grid(n,vector<char> (m));
    forn(i,n){
        forn(j,m){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                start={i,j};
            }
            else if(grid[i][j]=='B'){
                end={i,j};
            }

        }
    }

    map<pii,char> parent;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pii> q;
    q.push(start);
    parent[start]='?'; // source
    bool found=false;
    visited[start.F][start.S]=true;

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(auto [dx,dy]:directions){
            int X=x+dx;
            int Y=y+dy;
            if(X>=0 && X<n && Y>=0 && Y<m 
                && grid[X][Y]!='#' && !visited[X][Y]){
                visited[X][Y]=true;
                parent[{X,Y}]= (dx==1 && dy==0)?'D':
                               (dx==-1 && dy==0)?'U':
                               (dx==0 && dy==1)?'R':'L';
                q.push({X,Y});
                if(X==end.F && Y==end.S){
                    found=true;
                    break;
                }

            }
        }
    }

    string path="";
    if(!found){
        cout<<"NO"<<endl;
        return;
    }else{
        auto [x,y]=end;
        while(!(parent[{x,y}]=='?')){
            char p=parent[{x,y}];
            path+=p;
            if(p=='D') x--;
            else if(p=='U') x++;
            else if(p=='R') y--;
            else if(p=='L') y++;
        }
    }


    reverse(all(path));


    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;
    return;
    
    
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