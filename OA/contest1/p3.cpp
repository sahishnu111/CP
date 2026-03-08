#include <bits/stdc++.h>
using namespace std;

long long findBalancedRouting(vector<long long>& connections, long long k) {

    long long ans = 0;

    // (pref[j]%k - j)%k  == (pref[i-1] -i +1) %k 
    int n=connections.size();
    vector<long long> pref(n,0);

    for(int i=0;i<n;i++){
        
    }

    return ans;
}

void solve() {
    int n;
    long long k;

    cin >> n;

    vector<long long> connections(n);

    for(int i = 0; i < n; i++)
        cin >> connections[i];

    cin >> k;

    cout << findBalancedRouting(connections, k) << "\n";
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