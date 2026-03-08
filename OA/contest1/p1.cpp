#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<long long> pf(n + 1, 0);
    for(int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + a[i - 1];

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout<< pf[r] - pf[l - 1] << "\n";
        


        long long ans = 0;

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}