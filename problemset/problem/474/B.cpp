#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)x.size()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define mod 1000000007
#define inf 1e18

void solve() {
    // Your code here
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vll pre(n+1,0);
    for(int i=0;i<n;i++){ 
        pre[i + 1] = pre[i] + a[i];
    }

    int queries;
    cin>>queries;
    while(queries--){
        int x;
        cin>>x;
        //binary search
        int l=1,r=n;
        int res=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(pre[m]>=x){
                res=m;
                r=m-1;
            } else {
                l=m+1;
            }
        }
        cout << res << endl;
    }




    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}