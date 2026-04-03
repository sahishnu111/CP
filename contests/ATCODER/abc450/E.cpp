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

const int K=90;

ll FREQ(int k,long long r,char c,string &S1,string &S2, vector<ll> &len, vector<vector<ll>> &freq){
    if(r==0) return 0;

    // base case s1
    if(k==1){
        ll cnt=0;
        for(int i=0;i<min((ll)S1.size(),r);i++){
            if(S1[i]==c) cnt++;
        }
        return cnt;
    }

    // base case s2
    if(k==2){
        ll cnt=0;
        for(int i=0;i<min((ll)S2.size(),r);i++){
            if(S2[i]==c) cnt++;
        }
        return cnt;
    }

    if(r<=len[k-1]){
        return FREQ(k-1,r,c,S1,S2,len,freq);
    }
    else{
        return freq[k-1][c-'a'] + FREQ(k-2,r-len[k-1],c,S1,S2,len,freq);
    }
    
}

void solve() {

    string S1, S2;
    cin >> S1 >> S2;

    vector<ll> len(K+1);
    vector<vector<ll>> freq(K+1, vector<ll>(26));

    len[1] = S1.size();
    len[2] = S2.size();

    for(char c:S1) freq[1][c-'a']++;
    for(char c:S2) freq[2][c-'a']++;

    for(int i=3;i<=K;i++){
        len[i]=min((ll)2e18, len[i-1]+len[i-2]); 
        for(int c=0;c<26;c++){
            
            freq[i][c]=min((ll)2e18, freq[i-1][c]+freq[i-2][c]);
        }
    }

    int q;
    cin >> q;
    while(q--){
        long long l, r;
        char c;
        cin >> l >> r >> c;
        cout << FREQ(K,r,c,S1,S2,len,freq) - FREQ(K,l-1,c,S1,S2,len,freq) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}