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

struct Edge {
    int to;
    int id;
};

class Graph{
    int n;
    vector<vector<Edge>> adj;
    int max_days;
    vvi days;
    public:
        Graph(int nodes){
            this->n=nodes;
            adj.resize(n+1);
            max_days=0;
        }

        void add_edge(int u,int v,int id){
            adj[u].push_back({v,id});
            adj[v].push_back({u,id});

            //ans is determine maximum degree in tree
            max_days=max(max_days,(int)adj[u].size());
            max_days=max(max_days,(int)adj[v].size());
        }


        void dfs(int n,int parent,int parentColor){
            int currColor=1;
            for(auto &e:adj[u]){
                if(e.to==parent) continue;
                if(currColor==parentColor){
                    // we will just skip this color
                    currColor++;
                }
                days[currColor].push_back(e.id);
                dfs(e.to,u,currColor);
                currColor++;
            }
        }



        void colorSolve(){
            days.resize(max_days+1);

            dfs(1,0,0);

            cout<<max_days<<endl;
            for1(i,max_days){
                cout<<days[i].size()<<" ";
                for(auto &id:days[i]){
                    cout<<id<<" ";
                }

                cout<<endl;
            }
        }


};

void solve() {
    // Your code here
    int n;
    cin>>n;
    Graph g(n); 

    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        g.add_edge(u,v,i);
    }
    g.colorSolve();
    
    
    
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