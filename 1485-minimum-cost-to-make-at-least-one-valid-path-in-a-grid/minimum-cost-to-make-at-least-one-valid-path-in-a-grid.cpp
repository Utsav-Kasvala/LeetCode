class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<pair<int,int>> moves={{0,1},{0,-1},{1,0},{-1,0}};
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,m*n+5));

        dist[0][0]=0;

        pq.push({0,0,0});

        while(pq.size()>0){
            auto it=pq.top();
            pq.pop();
            int wt=it[0],x=it[1],y=it[2];
            //cout<<wt<<" "<<x<<" "<<y<<"\n";
            for(int k=0;k<4;k++){
               int nx=x+moves[k].first,ny=y+moves[k].second;
               if(nx>=0 && ny>=0 && nx<m && ny<n){
                  if(k==grid[x][y]-1){
                      if(dist[nx][ny]>wt){
                        dist[nx][ny]=wt;
                         pq.push({wt,nx,ny});
                      } 
                   }
                   else if(dist[nx][ny]>wt+1){
                      dist[nx][ny]=wt+1;
                      pq.push({wt+1,nx,ny});
                   }

               }
            }

        }


        return dist[m-1][n-1];

    }
};