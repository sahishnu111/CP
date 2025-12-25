#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pref[i] = pref[i - 1] ^ x;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (pref[b] ^ pref[a - 1]) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //solve();

    

    return 0;
}
