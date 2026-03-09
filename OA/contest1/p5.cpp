#include <bits/stdc++.h>
using namespace std;

int findLongestStableSegment(vector<long long>& signals, long long k) {

    int ans = 0;

    // a signal stability is max(signals[i..j]) - min(signals[i..j]) <=k
    // we need to mantain max and min of current window
    int n = signals.size();
    deque<int> maxd, mind;

    int left = 0,right = 0;
    while(right < n){
        while(!maxd.empty() && signals[maxd.back()] <= signals[right]){
                maxd.pop_back();
        }
        while(!mind.empty() && signals[mind.back()] >= signals[right]){
                mind.pop_back();
        }

        maxd.push_back(right);
        mind.push_back(right);

        while(signals[maxd.front()]-signals[mind.front()] > k){
            if(maxd.front() == left) maxd.pop_front();
            if(mind.front() == left) mind.pop_front();
            left++;
        }

        ans = max(ans, right - left + 1);

        right++;
    }


    return ans;
}

void solve() {
    int n;
    long long k;

    cin >> n;

    vector<long long> signals(n);

    for(int i = 0; i < n; i++)
        cin >> signals[i];

    cin >> k;

    cout << findLongestStableSegment(signals, k) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}