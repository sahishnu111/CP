#include <bits/stdc++.h>
using namespace std;

int findShortestStableCluster(vector<long long>& loads, long long k, long long s) {

    int ans = -1;

    // write logic here

    return ans;
}

void solve() {
    int n;
    long long k, s;

    cin >> n;

    vector<long long> loads(n);

    for(int i = 0; i < n; i++)
        cin >> loads[i];

    cin >> k >> s;

    cout << findShortestStableCluster(loads, k, s) << "\n";
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