#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long findBalancedRouting(vector<int>& a, int k) {
    int n = a.size();
    long long s = 0, r = 0, ls = 0; // s: sum, r: result, ls: left-window sum
    int c = 0, l = 0, lc = 0;      // c: odd count, l: left index, lc: left odd count
    unordered_map<long long, int> m;

    // (P[-1] - C[-1]) % k = 0
    m[0] = 1;
    vector<int> o = {-1}; // odd indices

    for (int j = 0; j < n; j++) {
        s += a[j];
        if (a[j] % 2 != 0) {
            c++;
            o.push_back(j);
        }

        // Subarray odd count must be < k. Remove invalid prefixes.
        if (c >= k) {
            int t = o[c - k + 1];
            while (l <= t) {
                long long u = (ls - lc) % k;
                if (u < 0) u += k;
                m[u]--;
                ls += a[l];
                if (a[l] % 2 != 0) lc++;
                l++;
            }
        }

        // (Pj - Cj) % k == (Pi-1 - Ci-1) % k
        long long v = (s - c) % k;
        if (v < 0) v += k;

        auto it = m.find(v);
        if (it != m.end()) r += it->second;

        m[v]++;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    cout << findBalancedRouting(a, k) << endl;
    return 0;
}