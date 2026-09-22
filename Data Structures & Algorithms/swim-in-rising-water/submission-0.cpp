class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

    pq.push({grid[0][0],{0,0}});
    int max_level=0;

    while(!pq.empty()){

        int r = pq.top().second.first;
        int c= pq.top().second.second;
        int level= pq.top().first;

        pq.pop();

        if(visited[r][c])  continue;

        visited[r][c]=1;


        max_level=max(max_level, level);

        if(r==n-1 && c==n-1)  return max_level;

        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};

        for(int i=0;i<4;i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow>=0 && ncol>=0  && nrow<n && ncol< n && !visited[nrow][ncol]){
                pq.push({grid[nrow][ncol],{nrow,ncol}});
            }

           
        }
    }

     return max_level;   
    }
};
