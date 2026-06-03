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
    string s;
    cin >> s;
    int n = s.size();
    

    map<char,int> freq;
    for(char c : s){ freq[c]++; }

    int mx=0;
    for(const auto& pair : freq) {
        if(pair.second > mx) {
            mx = pair.second;
        }
    }

    // m<=ceil(n+1)/2
    if(mx > (n+1)/2) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;


    vector<pair<int, char>> FREQ;
    for(auto& p : freq) {
        FREQ.pb({p.second, p.first}); 
    }
    sort(FREQ.rbegin(), FREQ.rend()); // dec

    // 0 2 4 6 8 .. 
    // 1 3 5 7 9 ..
    string ans(n,' ');
    int idx=0;
    
    for(auto &p: FREQ){
        char c = p.second;
        int f = p.first;
        
        while(f > 0){
            if(idx >= n) {
                idx = 1;
            }
            ans[idx] = c;
            idx += 2;
            f--;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test;
    cin >> test; 
    while (test--) {
        solve();
    }
    return 0;
}