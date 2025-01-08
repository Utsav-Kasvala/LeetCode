class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // O(n*300)
        int n=nums.size();
        int fans=0;
        vector<vector<int>> dp(301,vector<int>(301,0));
        for(int i=0;i<n;i++){
           int maxi=0;
           for(int diff=300;diff>=0;diff--){
              // curr = nums[i] // prev = curr-diff or curr + diff
              int c1=nums[i]-diff;
              int c2=nums[i]+diff;
              
              if(c1>=0){
                maxi=max(maxi,dp[c1][diff]);
              }

              if(c2<=300){
                maxi=max(maxi,dp[c2][diff]);
              }

              dp[nums[i]][diff]=1+maxi;
              fans=max(maxi,fans);
           }
        }


        return fans+1;
    }
};