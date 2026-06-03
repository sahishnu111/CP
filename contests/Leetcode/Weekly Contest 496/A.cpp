#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(36, 0); // 26 letters + 10 digits

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                freq[c - 'a']++;
            } else {
                freq[26 + (c - '0')]++;
            }
        }

        int ans = 0;

        for (int i = 0; i < 13; ++i) {
            ans += abs(freq[i] - freq[25 - i]);
        }

        
        for (int i = 0; i < 5; ++i) {
            ans += abs(freq[26 + i] - freq[26 + (9 - i)]);
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        string s;
        cin >> s;
        Solution sol;
        cout << sol.mirrorFrequency(s) << endl;
    }
    return 0;
}