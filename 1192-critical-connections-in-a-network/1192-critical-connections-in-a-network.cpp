class Solution {
public:
  
  void DFS(int node ,int parent ,vector<vector<int>>&adj ,vector<int>&dis ,vector<int>&low ,vector<bool>&visited ,vector<vector<int>>&bridges ,int count)
  {
    dis[node]=low[node]=count ;
    visited[node]=1 ;
    for(int j=0 ;j<adj[node].size() ;j++)
    {
        int neigh=adj[node][j] ;
        if(neigh==parent)
        continue ;

        else if(visited[neigh])
        low[node]=min(low[neigh],low[node]);

        else{
            count++;
            DFS(neigh,node ,adj,dis,low,visited,bridges,count);
            if(low[neigh]>dis[node])
            {
                vector<int>temp ;
                temp.push_back(node) ;
                temp.push_back(neigh) ;
                bridges.push_back(temp) ;
            }
            low[node]=min(low[node],low[neigh]) ;
        }

    }

  }
  
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>>adj(n) ;
        for(auto edge:connections)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u) ;
        }
        vector<vector<int>>bridges ;
        vector<int>dis(n) ;
        vector<int>low(n) ;
        vector<bool>visited(n) ;
        DFS(0,-1,adj,dis,low,visited,bridges,0) ;
        return bridges ;
    }
};