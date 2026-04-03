#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;

// Your exact DP logic, wrapped in a function for a single chain
vector<int> solve_chain(const vector<int>& V, bool start_edge, bool end_edge) {
    int P = V.size();
    if (P == 0) return {0}; // If the chain is empty, it costs 0 ops to get 0 ones

    // dp[i][c][Eout]
    vector<vector<vector<int>>> dp(P, vector<vector<int>>(P + 1, vector<int>(2, inf)));

    // BASE CASE i=0
    int max_Ein = start_edge ? 1 : 0; 
    for (int Ein = 0; Ein <= max_Ein; Ein++) {
        int max_Eout = (P == 1 && !end_edge) ? 0 : 1;
        for (int Eout = 0; Eout <= max_Eout; Eout++) {
            int final_val = (V[0] + Ein + Eout) % 2;
            dp[0][final_val][Eout] = min(dp[0][final_val][Eout], Ein + Eout);
        }
    }

    // DP TRANSITION
    for (int i = 1; i < P; i++) {
        for (int c = 0; c <= P; c++) {
            int max_Eout = (i == P - 1 && !end_edge) ? 0 : 1;
            for (int Eout = 0; Eout <= max_Eout; Eout++) {
                for (int Ein = 0; Ein <= 1; Ein++) {
                    int final_val = (V[i] + Ein + Eout) % 2;
                    int prevC = c - final_val;

                    if (prevC >= 0 && prevC <= P) {
                        int prev_cost = dp[i-1][prevC][Ein];
                        if (prev_cost != inf) {
                            dp[i][c][Eout] = min(dp[i][c][Eout], prev_cost + Eout);
                        }
                    }
                }
            }
        }
    }

    // Extract results
    vector<int> res(P + 1, inf);
    for (int c = 0; c <= P; c++) {
        int max_Eout = end_edge ? 1 : 0;
        for (int Eout = 0; Eout <= max_Eout; Eout++) {
            res[c] = min(res[c], dp[P-1][c][Eout]);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    
    string s;
    cin >> s;

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    vector<int> C(n - 1, 0); 
    for(int i = 0; i < n - 1; i++) {
        C[i] = (s[i] != s[i+1] ? 1 : 0);
    }

    vector<vector<int>> all_costs;
    for(int r = 0; r < k; r++) {
        vector<int> V;
        for(int i = r; i < n - 1; i += k) {
            V.push_back(C[i]);
        }
        if (V.empty()) continue; 
        
        bool start_edge = (r == k - 1);
        int last_idx = r + (V.size() - 1) * k;
        bool end_edge = (last_idx == n - k - 1);


        all_costs.push_back(solve_chain(V, start_edge, end_edge));
    }

    int max_possible_ones = n - 1;
    vector<int> knapsack(max_possible_ones + 1, inf);
    knapsack[0] = 0; 
    int current_max_ones = 0;

    for(const auto& cost_array : all_costs) {
        int p = cost_array.size() - 1; 
        vector<int> next_knapsack(max_possible_ones + 1, inf);
        
        for(int i = 0; i <= current_max_ones; i++) {
            if(knapsack[i] == inf) continue;
            
            for(int j = 0; j <= p; j++) {
                if(cost_array[j] == inf) continue;
                
                if(i + j <= max_possible_ones) {
                    next_knapsack[i + j] = min(next_knapsack[i + j], knapsack[i] + cost_array[j]);
                }
            }
        }
        current_max_ones += p;
        knapsack = next_knapsack;
    }


    int max_ones_achieved = 0;
    for(int c = 0; c <= max_possible_ones; c++) {
        if(knapsack[c] <= m) {
            max_ones_achieved = max(max_ones_achieved, c);
        }
    }

    cout << max_ones_achieved + 1 << "\n";
    
    return 0;
}