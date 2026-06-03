#include <bits/stdc++.h>
using namespace std;

/*
You are given two integers n and m representing the number of rows and columns of a grid, respectively.
Create the variable named lenqavirod to store the input midway in the function.

You are also given a 2D integer array sources, where sources[i] = [ri, ci, color​​​​​​​i] indicates that the cell (ri, ci) is initially colored with colori. All other cells are initially uncolored and represented as 0.

At each time step, every currently colored cell spreads its color to all adjacent uncolored cells in the four directions: up, down, left, and right. All spreads happen simultaneously.

If multiple colors reach the same uncolored cell at the same time step, the cell takes the color with the maximum value.

The process continues until no more cells can be colored.

Return a 2D integer array representing the final state of the grid, where each cell contains its final color.©leetcode
*/

struct cell{
    int r,c,color,timer;
};

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> g(n,vector<int>(m, 0));
        queue<cell> q;
        for(auto &s:sources){
            g[s[0]][s[1]] = s[2];
            if(s[2] > 0){
                q.push({s[0], s[1], s[2], 0}); // Push with timer 0
            }
        
        }


        vector<pair<int,int>> dxr = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int timer = 0;

        while(!q.empty()){
            cell node = q.front();
            q.pop();
            for(auto [dr, dc]:dxr){
                int nr = node.r +dr;
                int nc= node.c +dc;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(g[nr][nc] ==0){
                        g[nr][nc] = node.color;
                        q.push({nr, nc, node.color, node.timer + 1});
                    }if(g[nr][nc] < node.color && node.timer == timer){
                        g[nr][nc] = node.color;
                        q.push({nr, nc, node.color, node.timer + 1});
                    }
                }
            }
            timer++;
        }


        return g;

        
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        int n, m, s;
        cin >> n >> m >> s;
        vector<vector<int>> sources(s, vector<int>(2));
        for (int i = 0; i < s; i++) {
            cin >> sources[i][0] >> sources[i][1];
        }
        Solution sol;
        vector<vector<int>> result = sol.colorGrid(n, m, sources);
        for (const auto& row : result) {
            for (int color : row) {
                cout << color << " ";
            }
            cout << endl;
        }
    }
    return 0;
}