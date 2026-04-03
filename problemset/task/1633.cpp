#include<bits/stdc++.h>
using namespace std;

void DiceCombinations(){
    // math for this dp is dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6]
    const long long MOD = 1000000007;
    int n;
    cin>>n;
    vector<long long> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]=(dp[i]+dp[i-j])%MOD;
            }
        }
    }
    cout<<dp[n]<<endl;
}

int main(){
    DiceCombinations();
    return 0;
}
