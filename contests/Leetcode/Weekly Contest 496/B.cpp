#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        // a<=b and a,b>0
        // x = a^3+b^3 then x is a good integer
        // 1<=n<=1e9
        // cube root 1e9 is around 1000, so we can brute force a and b up to 1000
        map<int,int> cnt;
        int lmt = cbrt(n)+1;
        for(long long a=1;a<=lmt;a++){
            for(long long b=a;b<=lmt;b++){
                long long x = a*a*a + b*b*b;
                if(x<=n) cnt[x]++;
            }
        }  
        vector<int> goodINT;
        for(const auto& pair : cnt) {
            if(pair.second >= 2) {
                goodINT.push_back(pair.first);
            }
        }
        return goodINT;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        int n;
        cin >> n;
        Solution sol;
        vector<int> result = sol.findGoodIntegers(n);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}