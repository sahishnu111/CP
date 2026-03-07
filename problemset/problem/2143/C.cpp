#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; ++i)

struct Node{
    int val;
    int profit;
};

class Graph{
    int V;
    vector<vector<Node>> adjList;
    vector<int> inDegree;
public:
    Graph(int V){
        this->V = V;
        adjList.resize(V);
        inDegree.resize(V,0);
    }

    void addEdge(int u,int v,int profitu,int profitv){
        adjList[u].push_back({v,profitu});
        inDegree[v]++;
    }

    vector<vector<Node>>& getAdj(){
        return adjList;
    }

    int getInDegree(int node){
        return inDegree[node];
    }

    void decInDegree(int node){
        inDegree[node]--;
    }
};

void solve() {
    int n;
    cin >> n;
    Graph g(n);

    forn(i,n-1){
        int u,v,profitu,profitv;
        cin >> u >> v >> profitu >> profitv;
        u--; v--;

        if(profitu > profitv){
            g.addEdge(v, u, profitu, profitv); // v -> u
        }else{
            g.addEdge(u, v, profitv, profitu); // u -> v
        }
    }

    queue<int> q;
    forn(i,n){
        if(g.getInDegree(i) == 0){
            q.push(i);
        }
    }

    int m = 0;
    vector<int> res(n);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res[curr] = ++m;

        for(auto &node : g.getAdj()[curr]){
            int nxt = node.val;
            g.decInDegree(nxt);
            if(g.getInDegree(nxt) == 0){
                q.push(nxt);
            }
        }
    }

    forn(i,n){
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
