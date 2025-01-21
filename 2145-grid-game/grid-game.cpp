class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long> prefix1(n+2,0) ,prefix2(n+2,0);

        for(int i=1;i<=n;i++){
            prefix1[i]+=prefix1[i-1];
            prefix1[i]+=grid[0][i-1];
            prefix2[i]+=prefix2[i-1];
            prefix2[i]+=grid[1][i-1];
        }
        


        long long ans=1e18;
        for(int i=1;i<=n;i++){
            long long next=0,prev=0;
            
            next=prefix1[n]-prefix1[i];
            
            prev=prefix2[i-1];
            ans=min(ans,max(next,prev));
           // cout<<next<<" "<<prev<<"\n";
        }

        return ans;
    }
};