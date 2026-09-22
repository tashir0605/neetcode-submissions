class Solution {
public:

    bool isCycle(int u, int v, vector<vector<int>>& Adj) {

        vector<int> visited(Adj.size(), 0);
        queue<int> q;

        q.push(u);
        visited[u] = 1;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            if(node == v)
                return true;   

            for(auto neigh : Adj[node]) {

                if(!visited[neigh]) {
                    visited[neigh] = 1;
                    q.push(neigh);
                }
            }
        }

        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> Adj(n + 1);

        for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            if(isCycle(u, v, Adj)) {
                return {u, v};
            }

        
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }

        return {};
    }
};
