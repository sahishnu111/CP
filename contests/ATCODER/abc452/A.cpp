#include <bits/stdc++.h>
using namespace std;

void solve() {
    int M, D;
    cin >> M >> D;

    if ((M == 1 && D == 7) ||
        (M == 3 && D == 3) ||
        (M == 5 && D == 5) ||
        (M == 7 && D == 7) ||
        (M == 9 && D == 9)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
