class Solution {
public:

   void dfs(int row, int col, vector<vector<int>>& heights,vector<vector<bool>> &grid){


    int m = heights.size();
    int n = heights[0].size();
   int delrow[]={-1,1,0,0};
   int delcol[]={0,0,-1,1};


  for(int i=0;i<4;i++){
    int nrow = row+delrow[i];
    int ncol= col+ delcol[i];

    if(nrow>=0 && ncol>=0 && ncol<n && nrow<m  && heights[row][col]<=heights[nrow][ncol] &&    !grid[nrow][ncol]){

        grid[nrow][ncol]=true;

        dfs(nrow, ncol, heights, grid);
        
    }
  }
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m= heights.size();
        int n=heights[0].size();
vector<vector<int>>result;
        vector<vector<bool>>pacific_visited(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic_visited(m,vector<bool>(n,false));

        

        for(int i=0;i<m;i++){
            pacific_visited[i][0]=true;
            atlantic_visited[i][n-1]=true;
        }

        for(int i=0;i<n;i++){
     pacific_visited[0][i]=true;
            atlantic_visited[m-1][i]=true;
        }

        for(int i=0;i<n;i++){
            dfs(0,i,heights,pacific_visited);
            dfs(m-1,i,heights,atlantic_visited);

        }

             for(int i=0;i<m;i++){
            dfs(i,0,heights,pacific_visited);
            dfs(i,n-1,heights, atlantic_visited);

        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific_visited[i][j] && atlantic_visited[i][j]){
                    result.push_back({i,j});
                }
            }
        }




    return result;

    }
};
