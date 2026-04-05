#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int countWalls(const vector<int> &walls, int L, int R) {
        if (L > R) return 0;
        auto it1 = lower_bound(walls.begin(), walls.end(), L); 
        auto it2 = upper_bound(walls.begin(), walls.end(), R); 
        return distance(it1, it2); 
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int,int>> robos(n);
        for(int i = 0; i < n; i++){
            robos[i] = {robots[i], distance[i]};
        }

        sort(robos.begin(), robos.end());
        sort(walls.begin(), walls.end());
        
        
        int dest = 0;
        vector<int> fw; 
        for(int w : walls){
            auto it = lower_bound(robos.begin(), robos.end(), make_pair(w, -1));
            if(it != robos.end() && it->first == w){
                dest++;
            } else {
                fw.push_back(w);
            }
        }

        
        vector<vector<int>> dp(n, vector<int>(2, 0));

        // base case
        int lReach0 = robos[0].first - robos[0].second; 
        int rReach0 = robos[0].first - 1; 

        dp[0][0] = countWalls(fw, lReach0, rReach0); 
        dp[0][1] = 0;

        for(int i = 1; i < n; i++){
            int p1 = robos[i-1].first, d1 = robos[i-1].second;
            int p2 = robos[i].first, d2 = robos[i].second;

            int R1Start = p1 + 1; 
            int R1End = min(p2 - 1, p1 + d1); 
            int wallsR1Right = countWalls(fw, R1Start, R1End);

            int L2Start = max(p1 + 1, p2 - d2); 
            int L2End = p2 - 1;
            int wallsR2Left = countWalls(fw, L2Start, L2End);

            int overlap = 0;

            int Ostart = max(R1Start, L2Start); 
            int Oend = min(R1End, L2End);
            if(Ostart <= Oend){
                overlap = countWalls(fw, Ostart, Oend);
            }

            int bothWall = wallsR1Right + wallsR2Left - overlap;
            dp[i][0] = max(dp[i-1][0] + wallsR2Left, dp[i-1][1] + bothWall);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1] + wallsR1Right); 
        }

        int last_R_start = robos[n-1].first + 1;
        int last_R_end = robos[n-1].first + robos[n-1].second;
        int last_right_walls = countWalls(fw, last_R_start, last_R_end);

        int max_dp = max(dp[n-1][0], dp[n-1][1] + last_right_walls);

        return dest + max_dp;
    }
};

int main() {
    Solution s;
    int n, m; 
    cin >> n >> m; 
    vector<int> robots(n), distance(n), walls(m);
    for (int i = 0; i < n; i++) cin >> robots[i];
    for (int i = 0; i < n; i++) cin >> distance[i];
    for (int i = 0; i < m; i++) cin >> walls[i];
    
    cout << s.maxWalls(robots, distance, walls) << endl;
    return 0;
}