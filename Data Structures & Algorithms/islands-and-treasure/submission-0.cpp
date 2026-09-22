class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
      queue<pair<int,int>> q;
        vector<vector<int>>visited(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
       int delrow[]= {-1,1,0,0};
       int delcol[]= {0,0,-1,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            

            q.pop();

            for(int i=0;i<4;i++){

                int nrow =r+delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==INT_MAX){  grid[nrow][ncol]=grid[r][c]+1;
                q.push({nrow,ncol});

                }
            }


        }


    }
};
