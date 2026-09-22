// class DSU(){

     
//    vector<int>parent, rank;
//   public:
   

//    void DSU(int n){
//         parent.resize(n,0);
//         rank.resize(n,0);

//       for(int i=0;i<n;i++){
//         parent[i]=i;

//       }
//     }

//    int   findParent(int u){
//         if(parent[u]==u){
//             return u;
//         }

//         return parent[u]=findParent(parent[u]);
//       }



//      void UnionByRank(int u, int v){
         
//          if(rank[u]>rank[v]){
//             parent[v]=u;
//          }
//          else if(rank[v]>rank[u]){
//             parent[u]=v;
//          }

//          else if (rank[u]==rank[v]){
//             parent[v]=u;
//          }
//      }


// };


class Solution {
public:
     
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<vector<pair<int,int>>> adj(points.size());

        for(int i = 0; i < points.size(); i++) {
            for(int j = 0; j < points.size(); j++) {

                int u = i;
                int v = j;

                int weight = abs(points[i][0] - points[j][0]) +
                             abs(points[i][1] - points[j][1]);

                adj[u].push_back({v, weight});
                adj[v].push_back({u, weight});
            }
        }

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, 0});

        vector<int> visited(n, 0);

        int sum = 0;

        while(!pq.empty()) {

            int node = pq.top().second;
            int weigh = pq.top().first;

            pq.pop();

            // Check first
            if(visited[node])
                continue;

            // Then mark visited
            visited[node] = 1;

            sum += weigh;

            for(int i = 0; i < adj[node].size(); i++) {

                int neigh = adj[node][i].first;
                int weight = adj[node][i].second;

                if(!visited[neigh]) {
                    pq.push({weight, neigh});
                }
            }
        }

        return sum;
    }
};
