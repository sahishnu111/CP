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
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vi firstIdx(7,-2);
    firstIdx[0]=-1; // prefix sum 0 at index -1
    ll currsum=0;
    ll mxlen=0;

    for(int r=0;r<n;r++){
        currsum+=a[r];

        int R=(currsum%7+7)%7;

        if(firstIdx[R]!=-2){

            mxlen=max(mxlen,(ll)(r - firstIdx[R]));
        }else{
            firstIdx[R]=r;
        }


    }
    cout<<mxlen<<endl;
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