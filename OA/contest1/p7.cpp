#include <bits/stdc++.h>
using namespace std;

long long calculateScoreDifference(vector<long long>& cards) {

    long long ans = 0;

    // write logic here

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<long long> cards(n);

    for(int i = 0; i < n; i++)
        cin >> cards[i];

    cout << calculateScoreDifference(cards) << "\n";
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