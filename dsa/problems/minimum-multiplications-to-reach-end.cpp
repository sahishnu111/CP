#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minimumMultiplications(vector<int> &arr,int start, int end) {
        int n=arr.size();
        unordered_map<int,int> dist;
        queue<pair<int,int>> q;
        q.push({0,start});
        dist.insert({start, 0});
        
        if(start == end) return 0;
        
        while(!q.empty()){
            auto curr=q.front();
            int steps=curr.first;
            int val=curr.second;
            q.pop();
            
            for(int a:arr){
                int V=(val*a)%100000;
                if(dist.find(V)==dist.end() || dist[V]>steps+1){
                    dist.insert({V, steps+1});
                    if(V==end) return steps+1;
                    q.push({steps+1,V});
                }
            }
        }
        return -1;
    }
};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    //cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution sol;
        cout << sol.minimumMultiplications(arr, start, end) << endl;
    }
    return 0;
}
