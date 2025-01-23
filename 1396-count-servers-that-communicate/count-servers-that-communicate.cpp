class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        map<int,int> row,column;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                      row[i]++;
                      column[j]++;
                }
            }
        }

        int ans=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(row[i]>1){
                    ans++;
                }
                  else if(column[j]>1){
                    ans++;
                }
                }
               
            }
        }


        return ans;
    }
};