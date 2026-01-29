#include <bits/stdc++.h>
using namespace std;


struct knight
{
    int x;
    int y;
    int moves;
};

class Solution {
public:
    vector<vector<int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    int minKnightMoves(int x, int y) {

        x = abs(x);
        y = abs(y);

        queue<knight> q;
        q.push({0, 0, 0});

        vector<vector<bool>> visited(310, vector<bool>(310, false));
        visited[2][2] = true;   // shifted (0,0)

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int X = curr.x;
            int Y = curr.y;
            int moves = curr.moves;

            if (X == x && Y == y) {
                return moves;
            }

            for (auto dir : directions) {
                int nx = X + dir[0];
                int ny = Y + dir[1];

                if (nx >= -2 && ny >= -2 && nx <= 307 && ny <= 307 &&
                    !visited[nx + 2][ny + 2]) {

                    visited[nx + 2][ny + 2] = true;
                    q.push({nx, ny, moves + 1});
                }
            }
        }
        return -1;
    }
};
