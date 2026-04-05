#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)x.size()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define mod 1000000007
#define inf 1e18

void solve() {
    int N;
    cin >> N;

    vector<pii> AB(N);
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }

    int M;
    cin >> M;

    vector<string> S(M);
    for (int i = 0; i < M; i++) {
        cin >> S[i];
    }

    bool exisit[12][12][26] = {}; 

    for (auto &t : S) {
        int len = t.size();
        for (int i = 0; i < len; i++) {
            exisit[len][i + 1][t[i] - 'a'] = true;
        }
    }

    for (auto &s : S) {

        if ((int)s.size() != N) {
            cout << "No\n";
            continue;  
        }

        bool q = false;

        for (int i = 0; i < N; i++) {
            int A = AB[i].F;
            int B = AB[i].S;

            char need = s[i];  

            if (!exisit[A][B][need - 'a']) {
                q = true;
                break;
            }
        }

        if (q) cout << "No\n";
        else cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}