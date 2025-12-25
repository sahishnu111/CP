#include <bits/stdc++.h>
using namespace std;

// ========================= MACROS =========================
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)((x).size())
#define endl '\n'

// ========================= LOOPS =========================
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define trav(a, x) for (auto& a : x)

// ========================= PAIRS =========================
#define F first
#define S second
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>

// ========================= VECTORS =========================
#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>

// ========================= MATH =========================
#define mod 1000000007
#define mod2 998244353
#define inf 1e18
#define PI 3.141592653589793238462

// ========================= UTILITY FUNCTIONS =========================
template<typename T> void read(vector<T>& v) { for(auto& x : v) cin >> x; }
template<typename T> void print(const vector<T>& v) { for(const auto& x : v) cout << x << " "; cout << endl; }
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T power(T a, T b, T m = mod) { T res = 1; while(b) { if(b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res; }
ll modInv(ll a, ll m = mod) { return power(a, m - 2, m); }

// ========================= DEBUG =========================
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl;
#define debugv(v) cerr << #v << " = "; for(auto& x : v) cerr << x << " "; cerr << endl;
#else
#define debug(x)
#define debug2(x, y)
#define debugv(v)
#endif

// ========================= SOLUTION =========================

void solve() {
    // Your code here
    
}

// ========================= MAIN =========================

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    
    int test = 1;
    cin >> test;
    
    for(int tc = 1; tc <= test; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    
    return 0;
}

/*
========================= NOTES =========================
- Always check for integer overflow (use ll when needed)
- Be careful with edge cases (n=0, n=1, empty array, etc.)
- Think about time/space complexity before coding
- Test with sample inputs before submitting
- Common bugs: off-by-one errors, integer division, modulo with negative numbers
- For interactive problems: cout.flush() or cout << endl (not '\n')

========================= COMMON PATTERNS =========================
1. Prefix/Suffix Arrays
2. Two Pointers
3. Sliding Window
4. Binary Search
5. DFS/BFS
6. Dynamic Programming
7. Greedy
8. Number Theory (GCD, LCM, Prime Factorization)
9. Segment Trees / Fenwick Trees
10. DSU (Disjoint Set Union)

========================= TIME COMPLEXITIES =========================
O(n log n) - ~10^6 operations: sorting, binary search
O(n) - ~10^8 operations: linear scan
O(n^2) - ~10^4 operations: nested loops
O(n^3) - ~500 operations: 3 nested loops
O(2^n) - ~20 elements: backtracking, subset generation
O(n!) - ~10 elements: permutations

========================= QUICK SNIPPETS =========================

// Binary Search
int l = 0, r = n - 1, ans = -1;
while(l <= r) {
    int mid = l + (r - l) / 2;
    if(check(mid)) {
        ans = mid;
        r = mid - 1;
    } else {
        l = mid + 1;
    }
}

// Prefix Sum
vll pref(n + 1, 0);
for1(i, n) {
    pref[i] = pref[i-1] + arr[i];
}
// sum[l, r] = pref[r] - pref[l-1]

// Prefix XOR
vll pref(n + 1, 0);
for1(i, n) {
    pref[i] = pref[i-1] ^ arr[i];
}
// xor[l, r] = pref[r] ^ pref[l-1]

// GCD of array
int g = arr[0];
for1(i, n-1) g = gcd(g, arr[i]);

// Prime Check
bool isPrime(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

// Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i*i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

========================= END =========================
*/
