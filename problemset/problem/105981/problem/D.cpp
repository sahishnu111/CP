#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: Prefix sums s[0..n]
    vll s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }

    ll S = s[n];  // total sum

    // Step 2: Prefix minimums P[i] = min(s[1..i])
    vll P(n + 1, LLONG_MAX);
    for (int i = 1; i <= n; i++) {
        P[i] = min(P[i - 1], s[i]);
    }

    // Step 3: Suffix minimums M[i] = min(s[i..n])
    vll M(n + 2, LLONG_MAX);
    for (int i = n; i >= 0; i--) {
        M[i] = min(M[i + 1], s[i]);
    }

    // Step 4: Check each rotation
    int ans = 0;
    for (int k = 0; k < n; k++) {
        bool ok = true;

        // Condition 1: future (no wrap)
        if (M[k + 1] < s[k]) ok = false;

        // Condition 2: wrapped part
        if (k > 0 && P[k] + S < s[k]) ok = false;

        if (ok) ans++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
