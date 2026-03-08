#include <bits/stdc++.h>
using namespace std;

int findLongestStableSegment(vector<long long>& signals, long long k) {

    int ans = 0;

    // write logic here

    return ans;
}

void solve() {
    int n;
    long long k;

    cin >> n;

    vector<long long> signals(n);

    for(int i = 0; i < n; i++)
        cin >> signals[i];

    cin >> k;

    cout << findLongestStableSegment(signals, k) << "\n";
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