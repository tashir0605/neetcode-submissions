class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        vector<vector<int>> visited(m, vector<int>(n,0));

        int fresh = 0;
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;

            q.pop();

            ans = max(ans,time);

            for(int i = 0; i < 4; i++){

                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && ncol >= 0 &&
                   nrow < m && ncol < n &&
                   !visited[nrow][ncol] &&
                   grid[nrow][ncol] == 1){

                    visited[nrow][ncol] = 1;

                    fresh--;

                    q.push({{nrow,ncol},time+1});
                }
            }
        }

        if(fresh > 0)
            return -1;

        return ans;
    }
};