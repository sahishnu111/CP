#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; ++i)

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    forn(i, n) cin >> coins[i];

    // dp[s] ek bitset hai jo store karega ki total sum 's' hone par 
    // kaun-kaun se sub-sums possible hain.
    // bitset size 501 rakhenge kyunki k max 500 hai.
    vector<bitset<501>> dp(k + 1);

    // Base case: 0 total sum ke saath 0 sub-sum possible hai.
    dp[0][0] = 1;

    for (int c : coins) {
        // Reverse loop taaki ek hi coin ek se zyada baar use na ho (Subset Sum logic)
        for (int s = k; s >= c; s--) {
            // Bitset Magic Line:
            // 1. dp[s-c]: Coin ko total sum mein liya par sub-sum mein nahi (Arya didn't use it)
            // 2. dp[s-c] << c: Coin ko total aur sub-sum dono mein liya (Arya used it)
            dp[s] |= (dp[s - c] | (dp[s - c] << c));
        }
    }

    // Ab dp[k] mein wo saare bits '1' honge jo Arya bana sakti hai
    vector<int> result;
    for (int x = 0; x <= k; x++) {
        if (dp[k][x]) {
            result.pb(x);
        }
    }

    // Output according to problem format
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}