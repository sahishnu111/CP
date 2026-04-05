#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int editDistance(string start, string target) {
        int n = start.size(), m = target.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(start[i-1]==target[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+ min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}); // delete, insert, replace
                }
            }
        }

        return dp[n][m];
    }
};


int main() {
    Solution s;
    string str1, str2;
    cin >> str1 >> str2;
    cout << s.editDistance(str1, str2) << endl;
    return 0;
}