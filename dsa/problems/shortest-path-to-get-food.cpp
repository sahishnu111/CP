#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    struct State {
        int dist;
        int row;
        int col;
    };
    
    int least=INT_MAX;
    void bfs(const vector<vector<char>> &grid, pair<int,int> start,pair<int,int> food){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dxr={{0,1},{1,0},{0,-1},{-1,0}};
        queue<State> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        q.push({0, start.first, start.second});
        visited[start.first][start.second] = true;
        
        while(!q.empty()){
            State curr = q.front();
            q.pop();
            
            if(curr.row==food.first && curr.col==food.second){
                least=min(least,curr.dist);
                return;
            }
            
            for(auto dir:dxr){
                int X=curr.row+dir[0];
                int Y=curr.col+dir[1];
                if(X>=0 && X<n && Y>=0 && Y<m && grid[X][Y]!='X' && !visited[X][Y]){
                    q.push({curr.dist+1, X, Y});
                    visited[X][Y] = true;
                }
            }
        }
    }
    
    int getFood(vector<vector<char>>& grid) {
       //Your Code Goes Here 
        int n=grid.size();
        if(n==0) return -1;
        int m=grid[0].size();
        pair<int,int> start;
        vector<pair<int,int>> foods;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='*'){
                    start={i,j};
                }
                else if(grid[i][j]=='#'){
                    foods.push_back({i,j});
                }
            }
        }
        
        // Find shortest path to any food
        for(auto food : foods) {
            bfs(grid,start,food);
        }
        if(least==INT_MAX) return -1;
        return least;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // You can add test cases here to test the Solution class if needed
    Solution sol;
    vector<vector<char>> grid = {
        {'O','#','O','#','O','O','X','#','X','O'},
        {'O','O','*','O','O','O','O','O','O','#'}
    };
    int result = sol.getFood(grid);
    cout << "Shortest path to get food: " << result << endl;
    return 0;
}