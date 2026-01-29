#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int distance;
    int x;
    int y;
    int range;
};


class Solution{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
            queue<Point> pq;
            int n=grid.size();
            int m=grid[0].size();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            pq.push({0,source.first,source.second,grid[source.first][source.second]});
            visited[source.first][source.second] = true;
            while(!pq.empty()){
                auto curr=pq.front();
                pq.pop();
                int dist=curr.distance;
                int x=curr.x;
                int y=curr.y;
                int range=curr.range;
                if(x==destination.first && y==destination.second) return dist;
                vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
                for(auto dir:directions){
                    for(int step=1;step<=range;step++){
                        int X=x+dir[0]*step;
                        int Y=y+dir[1]*step;
                        if(X>=0 && X<n && Y>=0 && Y<m){
                            if(grid[X][Y]==0) break;
                            if(!visited[X][Y]){
                                visited[X][Y] = true;
                                pq.push({dist+1,X,Y,grid[X][Y]});
                            }
                        }
                    }
                }
            }
            return -1;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> grid={
        {1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 0},{1, 0, 1, 0, 1}
    };
    pair<int,int> source={0,0};
    pair<int,int> destination={3,4};
    cout<<sol.shortestPath(grid,source,destination)<<endl;
    return 0;
}
