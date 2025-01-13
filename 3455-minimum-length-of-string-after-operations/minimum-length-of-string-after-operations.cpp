class Solution {
public:
    int minimumLength(string s) {
        map<char,int> mp;
        int ans=0;
        for(auto &val:s){
         mp[val]++; 
        }
        
        for(auto &val:mp){
            if(val.second%2==1){
                ans+=max(0,val.second-1);
            }
            else{
               ans+=max(0,val.second-2);
            }
        }
        
        return s.size()-ans;
    }
};