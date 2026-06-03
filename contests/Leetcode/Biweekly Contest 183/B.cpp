class Solution {
public:

    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();
        vector<long long> ev(k,0); // rem =x
        vector<long long> od(k,0); // rem =y

        for(int i=0;i<n;i++){
            int num=nums[i];
            int r= num%k;

            for(int t=0;t<k;t++){
                int up= (t-r+k)%k;
                int down= (r-t+k)%k;
                int cost = up;
                if(num-up>=0){
                    cost = min(cost,down);
                }

                if(i%2==0){
                    ev[t]+=cost;
                }else{
                    od[t]+=cost;
                }
            }
        }

        long long ans=-1;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x!=y){
                    long long curr = ev[x]+od[y];
                    if(ans==-1 || curr<ans){
                        ans=curr;
                    }
                }
            }
        }

        return ans;


    }
};