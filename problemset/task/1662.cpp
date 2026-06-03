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
//Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.
    int n;
    cin>>n;
    vi a(n);
    forn(i,n) cin>>a[i];
    // subarray sum is divisible by n if prefix_sum[j] % n == prefix_sum[i-1] % n
    // we can count the frequency of each prefix sum modulo n
    vector<long long> freq(n, 0);
    long long PS = 0;
    freq[0] = 1; // empty subarray has sum 0 which is divisible by n
    for(int i=0;i<n;i++){
        PS = (PS + a[i]) % n;
        if (PS < 0) PS += n;
        freq[PS]++;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += (ll)freq[i] * (freq[i] - 1) / 2; // choose 2 from freq[i] math is nC2 = freq[i]*(freq[i]-1)/2
    }

    cout<<ans<<endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        solve();
    }
    return 0;
}