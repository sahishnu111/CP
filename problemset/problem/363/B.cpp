#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = 0;
    int sum = 0;
    for (r = 0; r < m; r++) {
        sum += a[r];
    }

    int mi = sum;
    int lest = 0;

    // Now slide the window
    for (r = m; r < n; r++) {
        sum += a[r];
        sum -= a[l];
        l++;
        if (sum < mi) {
            mi = sum;
            lest = l;
        }
    }

    cout << lest + 1 << "\n"; 
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
}
