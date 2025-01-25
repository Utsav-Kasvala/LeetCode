class DisjointSet{
    public:
    vector<int> rank,size,par;
 
    DisjointSet(int n){
      rank.resize(n+1,0);
      par.resize(n+1);
      size.resize(n+1,1);
      for(int i=0;i<=n;i++){par[i]=i;}
    }
    int findupar(int v){
      if(par[v]==v)return v;
      
      return par[v]=findupar(par[v]);
    }
    
    void unionbyrank(int u,int v){
         int upu=findupar(u);
         int upv=findupar(v);
         if(upu==upv)return;
         
         if(rank[upu]>rank[upv]){
          par[upv]=upu;
         }
         else if(rank[upu]<rank[upv]){
          par[upu]=upv;
         }
         else{
          rank[upu]++;
          par[upv]=upu;
         }
    }
    void unionbysize(int u,int v){
         int upu=findupar(u);
         int upv=findupar(v);
         if(upu==upv)return;
         if(size[upu]>size[upv]){
          par[upv]=upu;
          size[upu]+=size[upv];
         }
         else{
          par[upu]=upv;
          size[upv]+=size[upu];
         }
    }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> v;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        DisjointSet ds(n+1);
        for(int i=0;i<n-1;i++){
           if(v[i+1].first-v[i].first<=limit)ds.unionbysize(v[i+1].second,v[i].second);
        }
        
        map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[ds.findupar(i)].push_back(nums[i]);
        }
        
        vector<int> ans;
        
        for(auto &val:mp){
            sort(val.second.rbegin(),val.second.rend());
        }
        
        for(int i=0;i<n;i++){
         ans.push_back(mp[ds.findupar(i)].back());
         mp[ds.findupar(i)].pop_back(); 
        }
        
        return ans;
        
    }
};