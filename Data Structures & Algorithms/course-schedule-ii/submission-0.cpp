class Solution {
public:

  
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> Adj(numCourses);

                for(int i=0;i<prerequisites.size();i++){
            int u= prerequisites[i][0];
            int v=prerequisites[i][1];

            Adj[v].push_back(u);
        }

        vector<int>Indegree(numCourses, 0);
queue<int>q;

        for(int u=0;u< numCourses; u++){
            for(auto v: Adj[u]){
              Indegree[v]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;
        vector<int>ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
          ans.push_back(node);
            count++;

            for(int i=0;i<Adj[node].size();i++){
                int neigh = Adj[node][i];
                Indegree[neigh]--;
                if(Indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        if(count!=numCourses){
            return {};
        }

        return ans;




    }
};
