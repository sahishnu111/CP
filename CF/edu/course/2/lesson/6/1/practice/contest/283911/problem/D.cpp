#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define endl '\n'

int BSlower(const vll &num, int q) {
    int l = 0, h = num.size();
    while (l < h) {
        int m = l + (h - l) / 2;
        if (num[m] >= q)
            h = m;
        else
            l = m + 1;
    }
    return l;
}

int BSUpper(const vll &num, int q) {
    int l = 0, h = num.size();
    while (l < h) {
        int m = l + (h - l) / 2;
        if (num[m] <= q)
            l = m + 1;
        else
            h = m;
    }
    return l;
}

void solve() {
    int n, q;
    cin >> n;

    vll A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    sort(A.begin(), A.end());   

    cin>>q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << BSUpper(A, r) - BSlower(A, l) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
