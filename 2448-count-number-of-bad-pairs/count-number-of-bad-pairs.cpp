class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;

        long long n=nums.size();
        map<long long,long long> mp;
        for(int i=0;i<n;i++){
           ans+=mp[i-nums[i]];
           mp[i-nums[i]]++;
        }

        ans=(n*(n-1))/2-ans;
        return ans;
    }
};