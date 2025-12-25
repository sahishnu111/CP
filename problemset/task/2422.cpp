#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool canDO(ll t, ll x, ll y, ll prints) {
    return (t / x + t / y) >= prints;
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    ll minTime = min(x, y);
    ll maxTime = max(x, y);

    if (n == 1) {
        cout << minTime << endl;
        return;
    }

    // we already make 1 copy in minTime
    ll need = n - 1;

    ll l = 0;
    ll h = maxTime * need;

    while (l < h) {
        ll m = l + (h - l) / 2;
        if (canDO(m, x, y, need)) {
            h = m;
        } else {
            l = m + 1;
        }
    }

    cout << l + minTime << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
