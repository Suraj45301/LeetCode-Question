class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1) ;
        for(auto p:times)
        {
            int u=p[0];
            int v=p[1];
            int w=p[2] ;

            adj[u].push_back({v,w}) ;

        }
       vector<int>dist(n+1,INT_MAX);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,k}) ;
       dist[k]=0 ;

       while(!pq.empty())
       {
         int node=pq.top().second ;
         int time=pq.top().first ;
         pq.pop() ;

         if(time>dist[node]) continue ;

         for(int j=0 ;j<adj[node].size() ;j++)
         {
            int neigh=adj[node][j].first ;
            int weight=adj[node][j].second ;

            if(weight+dist[node]<dist[neigh])
            {
                dist[neigh]=weight+dist[node] ;
                pq.push({dist[neigh],neigh}) ;
            }
         }
       }
       int ans=0 ;
       for(int i=1 ;i<=n ;i++)
       {
        if(dist[i]==INT_MAX)
        return -1 ;

        ans=max(ans,dist[i]) ;
       }
       return ans ;
    }
};