class Solution {
public:
    
    
    bool check(int mid,int n,int k,vector<vector<int>> &edges){
        vector<vector<int>> g(n+1);
        int t=edges.size();
        
        for(int i=0;i<t;i++){
           if(edges[i][2]<=mid){
               g[edges[i][1]].push_back(edges[i][0]);
           }
        }
        
        vector<int> vis(n+1,0);
        
        queue<int> q;
        q.push(0);
        vis[0]=1;
        
        while(q.size()>0){
           int top=q.front();
           q.pop();
           for(auto &val:g[top]){
               if(vis[val])continue;
               else{
                   q.push(val);
                   vis[val]=1;
               }
           }
        }
        bool b=1;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
              //cout<<i<<" ";
              b=0;
            }
        }
        
        return b;
        
    }
    
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int t=edges.size();
        int maxi=0;
        for(int i=0;i<t;i++){
          maxi=max(maxi,edges[i][2]);
        }
        
        int lo=0,hi=maxi,ans=0;
        
        while(hi>=lo){
            int mid=(hi+lo)/2;
            if(check(mid,n,threshold,edges)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        if(ans==0)return -1;
        //cout<<check(1,5,threshold,edges);
        
        return ans;
        
    }
};