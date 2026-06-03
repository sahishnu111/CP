#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

ll dp[20][11][2][2];

ll DIGI(string s){
    int n=s.size();
    memset(dp,0,sizeof(dp));

    //base case: i=0, no previous digit (10), tight constraint active (1), leading zero active (1)
    dp[0][10][1][1]=1;

    for(int i=0;i<n;i++){
        for(int p=0;p<=10;p++){
            for(int t=0;t<2;t++){
                for(int z=0;z<2;z++){
                    if(dp[i][p][t][z]==0) continue;

                    int lim = t ? (s[i]-'0') : 9;
                    for(int d=0;d<=lim;d++){
                        int nxt= t && (d==lim);
                        int nxz= z && (d==0);

                        // If not a leading zero, check adjacency rule
                        if (!nxz && d==p) continue;

                        int nxp = nxz ? 10 : d;
                        dp[i+1][nxp][nxt][nxz] += dp[i][p][t][z];
                    }
                }
            }
        }
    }

    // Sum all states at index n
    ll ans = 0;
    for(int p=0;p<=10;p++){
        for(int t=0;t<2;t++){
            for(int z=0;z<2;z++){
                ans += dp[n][p][t][z];
            }
        }
    }
    return ans;
}

void solve() {
    long long a, b;
    cin >> a >> b;
    
    // Calculate f(b) - f(a-1)
    cout << DIGI(to_string(b)) - DIGI(to_string(a - 1)) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        solve();
    }
    return 0;
}