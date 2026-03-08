#include <bits/stdc++.h>
using namespace std;

long long findSecurityLevel(vector<long long>& pid, long long k) {

    long long ans = 0;
    int n= pid.size();
    vector<long long> pref(n + 1, 0);
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + pid[i - 1];
    
    // ( pref[j] - pref[i - 1] )% k == (j-i+1) %k
    //  pref[j] % k == (pref[i - 1] + j - i + 1) % k
    // pref[j]%k == (pref[i-1] -i +1) %k + j%k
    // (pref[j]%k - j)%k  == (pref[i-1] -i +1) %k 

    unordered_map<int,int> freq;


    for(int i=0;i<=n;i++){
        if(i>=k){
            long long o=(pref[i-k]-i+k)%k;
            freq[o]--;
        }
        int m=(pref[i]-i)%k;
        if( freq.find(m)!=freq.end() ){
            ans+=freq[m];
        }else{
            freq[m]=0;
        }
        freq[m]++;
    }

    

    return ans;
}

void solve() {
    int n;
    long long k;

    cin >> n;

    vector<long long> pid(n);

    for(int i = 0; i < n; i++)
        cin >> pid[i];

    cin >> k;

    cout << findSecurityLevel(pid, k) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}