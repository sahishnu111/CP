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

class Graph{
    public:
        int n;
        int ap;
        int t;
        vector<vector<int>> adj;
        Graph(int n){
            this->n = n;
            adj.resize(n);
        }
        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        

        int getLCA(int u, int v, vector<int> &depth, vector<vector<int>> &up){
            if(depth[u]<depth[v]) swap(u,v);
            for(int i=t; i>=0; i--){
                if(depth[u]-(1<<i)>=depth[v]){
                    u = up[u][i];
                }
            }
            if(u==v) return u;
            for(int i=t; i>=0; i--){
                if(up[u][i]!=up[v][i]){
                    u = up[u][i];
                    v = up[v][i];
                }
            }
            return up[u][0];
        }
};

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<int> d(26);
        // 1 xor 0 = 1 even+1= odd
        // 1 xor 1 = 0 odd+1= even

        for(int i=0; i<26; i++){
            d[i] = 1<<i;
        }

        Graph g(n);
        for(auto &e: edges){
            g.addEdge(e[0], e[1]);
        }


        int t = 0;
        while((1<<t)<=n) t++;
        vector<vector<int>> up(n, vector<int>(t));
        vector<int> depth(n);
        function<void(int,int)> dfs = [&](int u, int p){
            up[u][0] = p;
            for(int i=1; i<t; i++){
                up[u][i] = up[up[u][i-1]][i-1];
            }
            for(int v: g.adj[u]){
                if(v!=p){
                    depth[v] = depth[u]+1;
                    dfs(v,u);
                }
            }
        };
        dfs(0,0);
        vector<bool> ans;
        for(string &q: queries){
            stringstream ss(q);
            string type;
            int u,v;
            ss >> type >> u >> v;
            if(type=="update"){
                s[u] = v;
            }else{
                int lca = g.getLCA(u,v,depth,up);
                int mask = 0;
                mask ^= d[s[u]-'a'];
                mask ^= d[s[v]-'a'];
                mask ^= d[s[lca]-'a'];
                ans.push_back((mask & (mask-1))==0);
            }
        }

        return ans;

        
        
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
Solution sol;
// Input: n = 3, edges = [[0,1],[1,2]], s = "aac", queries = ["query 0 2","update 1 b","query 0 2"]
// Output: [true,false]

int n = 3;
vector<vector<int>> edges = {{0,1},{1,2}};
string s = "aac";
vector<string> queries = {"query 0 2","update 1 b","query 0 2"};
vector<bool> result = sol.palindromePath(n, edges, s, queries);
for (bool b : result) cout << (b ? "true" : "false") << endl;

return 0;
}