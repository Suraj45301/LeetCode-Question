class Solution {
public:

    
    int countPaths(int n, vector<vector<int>>& roads) {
          const int MOD = 1e9+7;
        vector<vector<pair<int,int>>>adj(n) ;
        for(int i=0 ;i<roads.size() ;i++)
        {
            int u=roads[i][0] ;
            int v=roads[i][1] ;
            int w=roads[i][2] ;

            adj[u].push_back({v,w}) ;
            adj[v].push_back({u,w}) ;
        }

        vector<long long>dist(n,LLONG_MAX) ;
        vector<long long> way(n,0) ;
        priority_queue<
            pair<long long ,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>
        > pq;
        dist[0]=0 ;
        way[0]=1 ;
        pq.push({0,0}) ;
        while(!pq.empty())
        {
            int node=pq.top().second ;
            int w=pq.top().first ;
            pq.pop();

            if(w>dist[node]) continue ;

            for(int j=0 ;j<adj[node].size() ;j++)
            {
                int neigh=adj[node][j].first ;
                int weight=adj[node][j].second ;

                 if(dist[node]+weight <dist[neigh])
                 {
                    dist[neigh]=dist[node]+weight ;
                    way[neigh]=way[node] ;
                    pq.push({dist[neigh],neigh}) ;
                 }

                 else if(dist[node]+weight==dist[neigh])
                 {
                    way[neigh]=(way[node]+way[neigh])%MOD ;
                 }
            }

            
        }
        return way[n-1]%MOD ;
    }
};