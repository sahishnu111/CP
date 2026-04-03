#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++){
        arr[i].resize(n - i - 1);
        for(int j = 0; j < n - i - 1; j++){
            cin >> arr[i][j];
        }
    }

    for(int a = 0; a < n; a++){
        for(int b = a + 1; b < n; b++){
            for(int c = b + 1; c < n; c++){
                if(arr[a][b - a - 1] + arr[b][c - b - 1] < arr[a][c - a - 1]){
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}