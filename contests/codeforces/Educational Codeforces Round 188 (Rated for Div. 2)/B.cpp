#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;


    vector<int> mx(n);
    mx[0] = a[0];
    for(int i = 1; i < n; i++) {
        mx[i] = max(mx[i-1], a[i]);
    }

    int res = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == mx[i]) {
            res++;
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}