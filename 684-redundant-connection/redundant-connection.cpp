class Solution {
public:
    vector<int> par;
    vector<int> sz;

    int findupar(int u){
        if(par[u]==u)return u;

        return par[u]=findupar(par[u]);
    }

    void unionbysz(int u,int v){
        int upar=findupar(u);
        int vpar=findupar(v);

        if(upar==vpar)return;

        if(sz[upar]>sz[vpar]){
            par[vpar]=upar;
            sz[upar]+=sz[vpar];
        }
        else{
            par[upar]=vpar;
            sz[vpar]+=sz[upar];
        }

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        int n=edges.size();

        par.resize(1002,0);
        sz.resize(1002,1);

        for(int i=1;i<=n;i++)par[i]=i;

         
         for(int i=0;i<n;i++){
            int a=edges[i][0],b=edges[i][1];

            if(findupar(a)==findupar(b)){
                return {a,b};
            }
            else{
                 unionbysz(a,b); 
            }
         
        }

        


       return {};
    }
};