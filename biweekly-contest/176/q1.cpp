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

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        unordered_map<char, int> wt;
        for(int i=0; i<26; i++){
            wt['a' + i] = weights[i];
        }
        for(int i=0; i<words.size(); i++){
            int sum = 0;
            for(char c: words[i]){
                sum+= wt[c];
            }
            sum= sum % 26;
            char t = 'z' - sum;
            result += t;
        }
        return result;
    }
};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution sol;
    vector<string> words = {"abcd", "def", "xyz"};
    vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    cout << sol.mapWordWeights(words, weights) << endl;
    return 0;
}