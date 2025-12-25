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
#define vil vector<ll>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define mod 1000000007
#define inf 1e18

void solve() {
    // Your code here
    int n;
    cin>>n;
    vil a(n+1,0);
    
    for(int i=0;i<n;i++){
        cin>>a[i+1];
    }

    //prefix sum
    vil pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    sort(all(a));
    vil preS(n+1,0);
    for(int i=1;i<=n;i++){
        preS[i]=preS[i-1]+a[i];
    }

    int queries;
    cin>>queries;
    while(queries--){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            cout<<pre[r]-pre[l-1]<<endl;
        }else{
            cout<<preS[r]-preS[l-1]<<endl;
        }
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