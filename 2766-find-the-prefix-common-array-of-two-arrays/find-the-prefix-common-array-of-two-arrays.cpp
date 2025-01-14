class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int> mp;
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(mp[A[i]]==2)cnt++;
            if(mp[B[i]]==2 && A[i]!=B[i])cnt++;

            ans.push_back(cnt);
        }

        return ans;
    }
};