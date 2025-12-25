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

void BS(const vll &num,int q){
    int l=0;
    int h=num.size()-1;
    while(h>=l){
        int mid=l+(h-l)/2;
        if(num[mid]==q){
            cout<<"YES"<<endl;
            return;
        }
        else if(num[mid]>q){
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<"NO"<<endl;
    return;
}

void solve() {
    // Your code here
    int n,q;
    cin>>n>>q;

    vll A(n,0);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }


    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        BS(A,x);
    }
    
    return;

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