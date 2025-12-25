#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> pre(n,0);
    pre[0]=a[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    while(m--){
        int l,r;
        ll k;
        cin>>l>>r>>k;
        ll sum = 0;

        // sum of replaced segment
        sum += (r - l + 1) * k;

        // add elements after r
        if(r < n) sum += pre[n-1] - pre[r-1];
        // add elements before l
        if(l > 1) sum += pre[l-2];

        if(sum % 2 == 0){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test=1;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}

