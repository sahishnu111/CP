#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int x, y;
    cin >> x >> y;
    vector<ll> a(x);
    ll stotal = 0;

    for(int i = 0; i < x; i++){
        cin >> a[i];
        stotal += a[i];
    }

    if(stotal < y){ cout << -1 << endl; return; }
    if(stotal == y){ cout << 0 << endl; return; }

    ll sum = 0, left = 0, mx = 1e18;

    for(int right = 0; right < x; right++){
        sum += a[right];
        while(sum > y){
            sum -= a[left++];
            
        }
        if(sum == y){
            mx = min(mx, (ll)x - (right - left + 1));
        }
    }

    cout << (mx == (ll)1e18 ? -1 : mx) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;
    while(test--) solve();
}
