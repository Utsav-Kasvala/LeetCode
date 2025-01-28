class Solution {
public:
    vector<pair<int,int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis,int &count){
        vis[i][j]=1;
        count+=grid[i][j];
        int n=grid.size();
        int m=grid[0].size();
         for(int k=0;k<4;k++){
             int nx=moves[k].first+i;
             int ny=moves[k].second+j;
            if(nx>=0 && nx<n && ny>=0 && ny<m ){
                if(grid[nx][ny]!=0 && vis[nx][ny]==0)
                dfs(nx,ny,grid,vis,count);
            }
         }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]>0){
                    int count=0;
                    dfs(i,j,grid,vis,count);
                    maxi=max(count,maxi);
                }
            }
        }

        return maxi;
    }
};