class Solution {
public:
    bool canConstruct(string s, int k) {
        int ans=0,n=s.size();
        if(n==k)return true;
        vector<int> mp(26,0);

        int even=0,odd=0;

        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(mp[i]%2==0){
                even+=mp[i]/2;
            }
            else{
                even+=mp[i]/2;
                odd++;
            }
        }

        if(odd>k || n<k)return false;

        return true;

    }
};