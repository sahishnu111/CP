#include <bits/stdc++.h>
using namespace std;

class Solution{
  public: 
  int distinctSubsequences(string s, string t){
        int m = s.size(), n = t.size();
        int MOD = 1e9+7;
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));

        for(int i=0;i<=m;i++) dp[i][0] = 1;

        for(int i = 1 ; i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];


    }
};

int main(){
    Solution s;
    string str1, str2;
    cin >> str1 >> str2;
    cout << s.distinctSubsequences(str1, str2) << endl;
    return 0;
}