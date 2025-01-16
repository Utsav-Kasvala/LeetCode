class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a=nums1.size(),b=nums2.size();

        int ans=0;
        for(int i=0;i<a;i++){
            if(b%2==1)ans^=nums1[i];
        }
        for(int i=0;i<b;i++){
            if(a%2==1)ans^=nums2[i];
        }

        return ans;
    }
};