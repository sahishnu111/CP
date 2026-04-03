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

class DSU{
    public:
    vector<int> parent, color, sz0, sz1;
    int bk;
    bool bip;

    DSU(int n){
        parent.resize(n+1);
        color.resize(n+1, 0); 
        sz0.resize(n+1, 1);   
        sz1.resize(n+1, 0);   
        bk = 0;
        bip = true;
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x) {
            int p = parent[x];
            parent[x] = find(parent[x]);
            color[x] ^= color[p]; 
        }
        return parent[x];
    }

    int get_color(int x){
        find(x);
        return color[x];
    }

    bool UNION(int a,int b){
        int A = find(a);
        int B = find(b);
        int cA = get_color(a);
        int cB = get_color(b);

        if(A == B) {
            if(cA == cB) bip = false; // odd cycle
            return false;
        }

        bk -= min(sz0[A], sz1[A]);
        bk -= min(sz0[B], sz1[B]);

        if(sz0[A]+sz1[A] < sz0[B]+sz1[B]) {
            swap(A, B);
            swap(cA, cB);
        }

        parent[B] = A;
        int c_diff = cA ^ cB ^ 1;
        color[B] = c_diff;

        // merge
        if(c_diff == 0) {
            sz0[A] += sz0[B];
            sz1[A] += sz1[B];
        } else {
            sz0[A] += sz1[B];
            sz1[A] += sz0[B];
        }

        bk += min(sz0[A], sz1[A]);
        return true;
    }
};

void solve() {
   int n, q;
   cin >> n >> q;

   DSU dsu(n);

   while(q--){
        int x, y;
        cin >> x >> y;
        
        if(dsu.bip) {
            dsu.UNION(x, y);
        }
        
        if(!dsu.bip){
            cout << "-1\n";
        } else {
            cout << dsu.bk << "\n";
        }
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