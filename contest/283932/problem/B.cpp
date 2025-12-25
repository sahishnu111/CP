#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

int n, k;

bool dfs(const vi &num, double x) {   
    ll t = 0;
    for (int i = 0; i < num.size(); i++) {
        t += (ll)(num[i] / x);       
    }
    return t >= k;
}

void solve() {
    cin >> n >> k;

    vi A(n);
    double x = 0;

    for (int i = 0; i < n; i++) {    
        cin >> A[i];
        x += A[i];
    }

    double l = 0;
    double h = x;

    while (h - l > 1e-6) {           
        double m = l + (h - l) / 2;
        if (dfs(A, m)) {
            l = m;                   
        } else {
            h = m;
        }
    }

    cout << fixed << setprecision(6) << l << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
