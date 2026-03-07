#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

bool dfsCycle(int node, vector<int> adjlist[26], vector<int> &visited){
    visited[node] = 1;
    for(int nxt : adjlist[node]){
        if(visited[nxt] == 0){
            if(dfsCycle(nxt, adjlist, visited)) return true;
        } else if(visited[nxt] == 1){
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    forn(i, n) cin >> s[i];

    vector<int> adjlist[26];
    vector<int> inDegree(26, 0);
    vector<bool> used(26, false);

    // mark used letters
    for(int i = 0; i < n; i++){
        for(char c : s[i]){
            used[c - 'a'] = true;
        }
    }

    // ✅ CORRECT EDGE BUILDING
    for(int i = 0; i < n - 1; i++){
        int len = min(s[i].size(), s[i+1].size());
        bool found = false;

        for(int j = 0; j < len; j++){
            if(s[i][j] != s[i+1][j]){
                int u = s[i][j] - 'a';
                int v = s[i+1][j] - 'a';
                adjlist[u].push_back(v);
                inDegree[v]++;
                found = true;
                break;
            }
        }

        // prefix case → impossible
        if(!found && s[i].size() > s[i+1].size()){
            cout << "Impossible\n";
            return;
        }
    }

    // cycle detection
    vector<int> visited(26, 0);
    for(int i = 0; i < 26; i++){
        if(visited[i] == 0){
            if(dfsCycle(i, adjlist, visited)){
                cout << "Impossible\n";
                return;
            }
        }
    }

    // topological sort
    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }

    string result;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        if(used[curr])
            result += char(curr + 'a');
        for(int nxt : adjlist[curr]){
            if(--inDegree[nxt] == 0)
                q.push(nxt);
        }
    }

    // add unused letters at the end
    for(int i = 0; i < 26; i++){
        if(!used[i])
            result += char(i + 'a');
    }

    cout << result << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

