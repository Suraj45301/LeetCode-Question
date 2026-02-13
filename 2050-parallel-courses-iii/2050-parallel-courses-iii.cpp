class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
      vector<vector<int>>adj(n+1) ;
      vector<int>indeg(n+1,0) ;
      for(auto edge :relations)
      {
        int u=edge[0] ;
        int v=edge[1] ;

        adj[u].push_back(v) ;
        indeg[v]++ ;
      }

      vector<int>cnt(n+1,0) ;
      queue<int>q ;
      for(int i=1;i<=n ;i++)
      {
         if(indeg[i]==0)
         {
            q.push(i) ;
            cnt[i]=time[i-1] ;
         }
      }
      while(!q.empty())
      {
        int node=q.front() ;
        q.pop() ;

        for(int j=0 ;j<adj[node].size() ;j++)
        {
            int neigh=adj[node][j] ;
            indeg[neigh]-- ;
            cnt[neigh]=max(cnt[neigh],cnt[node]+time[neigh-1]) ;
            if(!indeg[neigh])
            q.push(neigh) ;

        }
      }
      int ans=0 ;
      for(int i=1 ;i<=n ;i++)
      {
        ans=max(ans,cnt[i]) ;
      }
      return ans ;
    }
};