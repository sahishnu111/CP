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
    int k,a,b;
    cin >> k >> a >> b;
    
    string s;
    cin >> s;
    // x1+x2+...+xk = s.size()
    // a<=xi<=b
    // a<= ceil(s.size()/k) <= b is false then cout<<"No solution\n";
    int n = s.size();
    if (n < k * a || n > k * b) {
        cout << "No solution\n";
        return;
    }


    int i=n/k;
    int rem = n%k;
    vector<string> ans; 
    // When you initialize a vector with a size k, it creates k empty strings. 
    // Then, your while loop uses push_back, which adds k more strings. This results in 2k strings total, 
    // where the first k are empty.
    int j=0;
    int line=0;
    while(line<k){
        // slice s[j:j+i]  
        int curr=i+(line<rem ? 1 : 0); 
        ans.push_back(s.substr(j, curr)); // slice s[j:j+curr] 
        j+=curr;
        line++;
    }


    // print ans
    for(string str : ans){
        cout << str << endl;
    }


    
    
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