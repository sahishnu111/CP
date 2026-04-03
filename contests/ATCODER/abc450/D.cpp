#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; ++i)

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    forn(i,n) cin>>a[i];

    vector<int> b(n);
    forn(i,n){
        b[i]=a[i]%k;
    }

    sort(all(b));

    int res = b[n-1] - b[0]; 
    forn(i,n){
        int diff = b[(i-1+n)%n] + k - b[i];
        res=min(res,diff);
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}