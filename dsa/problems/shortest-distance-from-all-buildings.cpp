#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    int y;
    /* data */
};


class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        // User code goes here

        int n=grid.size();
        int m=grid[0].size();
        int minDist=INT_MAX;

        vector<pair<int,int>> buildings;
        
        // Count total buildings
        int totalBuildings = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    totalBuildings++;
                    buildings.push_back({i, j});
                }
            }
        }


        // from every building calculate distance to every empty land
        vector<vector<int>> distanceSum(n, vector<int>(m, 0));
        
        for(auto b:buildings){
            queue<node> q;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            q.push({b.first,b.second});
            visited[b.first][b.second]=true;

            while(!q.empty()){
                auto curr=q.pop();
                int x=curr.x;
                int y=curr.y;
                vector<vector<int>> dxr={{0,1},{1,0},{0,-1},{-1,0}};
                for(auto dir:dxr){
                    int X=x+dir[0];
                    int Y=y+dir[1];
                    if(X>=0 && X<n && Y>=0 && Y<m && !visited[X][Y] && grid[X][Y]==0){
                        
                }
            }

        }
        

        




        // we will do bfs from each empty land
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    queue<node> q;
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    int currDist=0;
                    int buildingsReached=0;
                    
                    q.push({i,j,0});
                    visited[i][j]=true;
                    
                    while(!q.empty()){
                        auto curr=q.front();
                        q.pop();
                        int x=curr.x;
                        int y=curr.y;
                        int dist=curr.manhattanDistance;
                        
                        if(grid[x][y]==1){
                            currDist+=dist;
                            buildingsReached++;
                            continue; // Don't explore further from buildings
                        }
                        
                        vector<vector<int>> dxr={{0,1},{1,0},{0,-1},{-1,0}};
                        for(auto dir:dxr){
                            int X=x+dir[0];
                            int Y=y+dir[1];
                            
                            if(X>=0 && X<n && Y>=0 && Y<m && !visited[X][Y] && grid[X][Y]!=2){
                                visited[X][Y]=true;
                                q.push({X,Y,dist+1});
                            }
                        }
                    }
                    
                    if(buildingsReached == totalBuildings){
                        minDist=min(minDist, currDist);
                    }
                }
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> grid={
        {1,0,2,0,1},
        {0,0,0,0,0},
        {0,0,1,0,0}
    };   
    cout<< sol.shortestDistance(grid) << endl;
    return 0;
}