#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; ++i)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    forn(i, n) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; 
        b[i]--;
    }

    ll cost_clockwise = 0;
    ll cost_counter = 0;

    // Cities are in a ring: 0 -> 1 -> 2 -> ... -> n-1 -> 0

    forn(i, n) {
        int u = a[i];
        int v = b[i];

        // expected clockwise edge: u -> (u+1)%n
        int next = (u + 1) % n;

        if (v != next) {
            cost_clockwise += c[i];   // need to reverse
        } else {
            cost_counter += c[i];     // for counter direction, this one is wrong
        }
    }

    cout << min(cost_clockwise, cost_counter) << endl;
    return 0;
}
