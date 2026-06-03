#include <bits/stdc++.h>
using namespace std;    

lass Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        if sides[0]+sides[1] < sides[2] return {}; 
        if sides[1]+sides[2] < sides[0] return {};
        if sides[0]+sides[2] < sides[1] return {};
        int s=(sides[0]+sides[1]+sides[2])/2;
        int area = s*(s-sides[0])*(s-sides[1])*(s-sides[2]);
        // Heron's formula for area of triangle
        double A = sqrt(area);
        double A=2*A;
        vector<double> angles(3);
        angles[0] = asin((2*A)/(sides[1]*sides[2]))*180/M_PI;
        angles[1] = asin((2*A)/(sides[0]*sides[2]))*180/M_PI;
        angles[2] = asin((2*A)/(sides[0]*sides[1]))*180/M_PI;
        return angles;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        int n;
        cin >> n;
        vector<int> sides(n);
        for (int i = 0; i < n; i++) {
            cin >> sides[i];
        }
        Solution sol;
        vector<double> angles = sol.internalAngles(sides);
        for (double angle : angles) {
            cout << angle << " ";
        }
        cout << endl;
    }
    return 0;
}