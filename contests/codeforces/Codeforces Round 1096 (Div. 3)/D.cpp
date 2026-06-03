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
    int n;
    cin>>n;
    
    vector<pair<int,int>> t(n,{-1,-1});
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
        int x=a[i];
        if(t[x].first==-1){
            t[x].first=i;
        }else{
            t[x].second=i;
        }
    }

    int mids[3]={t[0].first+t[0].second,2*t[0].first,2*t[0].second};
    int mx=0;

    for(int m:mids){
        int l= m/2;
        int r= (m+1)/2;

        // outwards
        while(l>=0 && r<=2*n && a[l]==a[r]){
            l--;
            r++;
        }

        l++;
        r--;

        if(l<=r){
            vi cnt(n+1,0);
            for(int i=l;i<=r;i++){
                if(a[i]<n) cnt[a[i]]++;
            }

            int cmx=0;
            while (cnt[cmx]>0){
                cmx++;
            }

            mx = max(mx,cmx);
        }

    }

    cout<<mx<<endl;

    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    cin>>test;
    while (test--) {
        solve();
    }
    return 0;
}