#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> bfs(const vector<vector<int>> &rooms,pair<int,int> point,vector<vector<int>> &ans){
        int n=rooms.size();
        int m=rooms[0].size();
        vector<vector<int>> dxr={{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,pair<int,int>>> q; // distance ,(x,y)
        q.push({0,point});
        while(!q.empty()){
            auto curr=q.front();
            int dist=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            if(rooms[x][y]==-1) continue;
            q.pop();
            for(auto dir:dxr){
                int X=x+dir[0];
                int Y=y+dir[1];
                if(X>=0 && X<n && Y>=0 && Y<m && rooms[X][Y]!=-1){
                    if(ans[X][Y]>dist+1){
                        ans[X][Y]=dist+1;
                        q.push({dist+1,{X,Y}});
                    }
                }
            }
        }
        return ans;
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        // Your code goes here
        int n=rooms.size();
        if(n==0) return;
        int m=rooms[0].size();
        vector<vector<int>> ans(n,vector<int>(m,2147483647));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rooms[i][j]==0){
                    ans[i][j]=0;
                    ans=bfs(rooms,{i,j},ans);
                }
                else if(rooms[i][j]==-1){
                    ans[i][j]=-1;
                }
            }
        }
        rooms = ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
// You can add test cases here to test the Solution class if needed
Solution sol;
vector<vector<int>> rooms = {
    {2147483647,-1,0,2147483647},
    {2147483647,2147483647,2147483647,-1},
    {2147483647,-1,2147483647,-1},
    {0,-1,2147483647,2147483647}
};
sol.wallsAndGates(rooms);
for (const auto& row : rooms) {
    for (const auto& val : row) {
        cout << val << " ";
    }
    cout << endl;
}

return 0;
}


