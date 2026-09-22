class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        int V = n;

        vector<vector<pair<int,int>>> Adj(V);

        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int weights = flights[i][2];

            Adj[u].push_back({v, weights});
        }

        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq;

        int s = k;

        pq.push({0, {s, src}});

        vector<vector<int>> visited(V, vector<int>(k + 2, 0));

        while(!pq.empty()){

            int cost = pq.top().first;
            int step = pq.top().second.first;
            int node = pq.top().second.second;

            pq.pop();

            if(node == dst){
                return cost;
            }

            if(step < 0){
                continue;
            }

            if(visited[node][step]){
                continue;
            }

            visited[node][step] = 1;

            for(int i = 0; i < Adj[node].size(); i++){

                int wt = Adj[node][i].second;
                int next_node = Adj[node][i].first;

                pq.push({
                    cost + wt,
                    {step - 1, next_node}
                });
            }
        }

        return -1;
    }
};