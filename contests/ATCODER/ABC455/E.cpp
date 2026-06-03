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
    int n;
    string s;
    cin >> n >> s;

    vll A(n+1,0),B(n+1,0),C(n+1,0);

    for (int i = 0; i < n; i++) {
        A[i + 1] = A[i] + (s[i] == 'A');
        B[i + 1] = B[i] + (s[i] == 'B');
        C[i + 1] = C[i] + (s[i] == 'C');
    }

    map<ll,ll> mAB, mAC, mBC;
    map<pair<ll,ll>, ll> mABC;
    ll AB=0, AC=0, BC=0, ABC=0;

    for(int i=0;i<=n;i++){
        ll D_ab=A[i]-B[i];
        ll D_ac=A[i]-C[i];
        ll D_bc=B[i]-C[i];
        
        AB+=mAB[D_ab]++;
        BC+=mBC[D_bc]++;
        AC+=mAC[D_ac]++;

        ABC+=mABC[{D_ab,D_ac}]++;
    }

    ll t= (ll) n*(n+1)/2;
    ll inv= AB + AC + BC - 2*ABC;
    cout << t - inv << endl;
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