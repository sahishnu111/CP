#include<bits/stdc++.h>
using namespace std;

void DKnapsack(){
    int n,w;
    cin>>n>>w;
    vector<int> W(n),V(n);
    for(int i=0;i<n;i++) cin>>W[i]>>V[i];

    vector<long long> dp(w+1,0);
    for(int i=0;i<n;i++){
        for(int j=w;j>=W[i];j--){
            dp[j]=max(dp[j], (long long)V[i]+dp[j-W[i]]);
        }
    }
    cout<<dp[w]<<endl;
}

int main(){
    DKnapsack();
    return 0;
}
