#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    string x;
    cin >> n;
    cin >> x;
    
    int mn = 0, mx = 0; 

    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            int f = i;
            int l = i;
            
            
            for (int j = i + 1; j < n; j++) {
                if (x[j] == '1') {
                    
                    if (j - l <= 2) {
                        l = j;
                    } else {
                        break; 
                    }
                }
            }
            
            int L = l - f + 1;
            mn += (L / 2) + 1; 
            mx += L;           
            
            i = l; 
        }
    }
    
    cout << mn << " " << mx << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}