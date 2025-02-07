class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> ball;
        map<int,int> color;
        vector<int> ans;
        int n=queries.size();
        for(int i=0;i<n;i++){
           if(ball[queries[i][0]]==0){
               ball[queries[i][0]]=queries[i][1];
               color[queries[i][1]]++;
               ans.push_back(color.size());
           }
           else{
               color[ball[queries[i][0]]]--;
               if(color[ball[queries[i][0]]]==0)color.erase(ball[queries[i][0]]);
               color[queries[i][1]]++;
               ball[queries[i][0]]=queries[i][1];
               ans.push_back(color.size());
               
           }
        }
        
        return ans;
    }
};