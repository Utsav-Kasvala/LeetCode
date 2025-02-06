class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();

        map<int,int> mp;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }

        int ans=0;
        for(auto &val:mp)ans+=((val.second-1)*(val.second))/2;
        return 8*ans; 
    }
};