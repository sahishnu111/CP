#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {
    ll a, b, c, m;
    cin >> a >> b >> c >> m;

    
    ll cntA = m / a;
    ll cntB = m / b;
    ll cntC = m / c;
    
    ll cntAB = m / lcm(a, b);
    ll cntBC = m / lcm(b, c);
    ll cntAC = m / lcm(a, c);
    ll cntABC = m / lcm(lcm(a, b), c);


    
    ll wA = (cntA - cntAB - cntAC + cntABC) * 6
               + (cntAB - cntABC + cntAC - cntABC) * 3
               + cntABC * 2;
    
    ll wB = (cntB - cntAB - cntBC + cntABC) * 6
               + (cntAB - cntABC + cntBC - cntABC) * 3
               + cntABC * 2;
    
    ll wC = (cntC - cntAC - cntBC + cntABC) * 6
               + (cntAC - cntABC + cntBC - cntABC) * 3
               + cntABC * 2;

    cout << wA << " " << wB << " " << wC << "\n";
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