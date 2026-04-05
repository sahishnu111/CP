#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long long> A(N + 1, 0);
    vector<long long> P(N + 1, 0); 
    long long sumA = 0;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        P[i] = (P[i - 1] + A[i]) % MOD;
        sumA = (sumA + (A[i] * i) % MOD) % MOD;
    }

    vector<long long> B(M + 1, 0);
    long long sumB = 0;
    
    for (int j = 1; j <= M; ++j) {
        cin >> B[j];
        sumB = (sumB + B[j]) % MOD;
    }

    long long S1 = (sumA * sumB) % MOD;
    
    long long S2 = 0;

    for (int j = 1; j <= M; ++j) {
        long long iS = 0;
        
        for (long long k = 1; k * j <= N; ++k) {
            int L = k * j;
            int R = min((long long)N, (k + 1) * j - 1);
            
            long long range_sum = (P[R] - P[L - 1] + MOD) % MOD;
            long long term = (k * range_sum) % MOD;
            
            iS = (iS + term) % MOD;
        }
        
        long long term = (B[j] * j) % MOD;
        long long Fterm = (term * iS) % MOD;
        
        S2 = (S2 + Fterm) % MOD;
    }

    long long ans = (S1 - S2 + MOD) % MOD;
    cout << ans << "\n";

    return 0;
}