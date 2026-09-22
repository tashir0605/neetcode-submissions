class Solution {
public:
  

  bool isCycle(queue<pair<int,int>>&q, vector<vector<int>>&Adj,vector<int>&visited ){
    


    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for(int i=0;i<Adj[node].size();i++){
            if(!visited[Adj[node][i]]){
                visited[Adj[node][i]]=1;
                q.push({Adj[node][i],node});
            }
            else if(parent!=Adj[node][i]){
                return true;
            }
        }
    }

    return false;
           

   }
   

    bool validTree(int n, vector<vector<int>>& edges) {
      vector<vector<int>>Adj(n);

      for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v= edges[i][1];

        Adj[u].push_back(v);
        Adj[v].push_back(u);

      }
int component=0;
      vector<int>visited(n,0);
      queue<pair<int,int>>q;
      for(int i=0;i<n;i++){

        if(!visited[i]){
            component++;
             visited[i] = 1;
        q.push({i,-1});
          if(isCycle(q,Adj,visited)) return false;

      }




      
    }

    if (component>1) return false;
    else return true;
    }
};
