class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int  n=arr.size(), ans=1;
        for(int i=0;i<n-1;i++){
            int cnt=1;
            while(i<n-1){
                if(arr[i]<arr[i+1])cnt++;
                else break;
                i++;
            }
            ans=max(ans,cnt);
        }
        for(int i=0;i<n-1;i++){
            int cnt=1;
            while(i<n-1){
                if(arr[i]>arr[i+1])cnt++;
                else break;
                i++;
            }
            ans=max(ans,cnt);
        }
        
        return ans;
    }
};