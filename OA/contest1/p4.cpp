#include <bits/stdc++.h>
using namespace std;

int totalLCT(const string& s){
    int l=0;
    int lc=0;
    int lct=0;
    for(char i : s){
        if(i=='L') l++;
        else if(i=='C') lc+=l;
        else if(i=='T') lct+=lc;
    }
    return lct;
}

long long maxLCTSubsequence(const string& s) {

    long long ans = 0;

    long long gainL,gainT;
    string t1='L'+s;
    string t2=s+'T';
    gainL=totalLCT(t1)-totalLCT(s);
    gainT=totalLCT(t2)-totalLCT(s);

    // A new 'C' placed at some index i will pair with every 'L' that comes before i and every 'T' that comes after i
    // prefixL numbner of L in 0 to i-1
    // suffixT number of T in i to n-1
    // gainC= max(prefixL * suffixT) for all i

    long long prefixL=0;
    long long suffixT=0;
    for(char i : s){
        if(i=='T') suffixT++;
    }

    long long bestG=0;
    long long maxgainC=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        long long gain=prefixL * suffixT;
        if(gain> maxgainC){
            maxgainC=gain;
            bestG=i;

        }
        if(i<n){
            if(s[i]=='L') prefixL++;
            else if(s[i]=='T') suffixT--;

        }
    }

    string t3=s.substr(0,bestG)+'C'+s.substr(bestG);
    return max({totalLCT(t1), totalLCT(t2), totalLCT(t3)});

}

void solve() {
    string s;
    cin >> s;

    cout << maxLCTSubsequence(s) << "\n";
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