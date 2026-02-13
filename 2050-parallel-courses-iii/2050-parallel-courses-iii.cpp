class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>>adj(n+1) ;
        vector<int>indeg(n+1,0) ;
        for(auto &p :relations)
        {
            adj[p[0]].push_back(p[1]);
            indeg[p[1]]++ ;
        }
        vector<int>ct(n+1,0) ;
        queue<int>q ;
        for(int i=1 ;i<=n ;i++)
        {
            if(!indeg[i])
            {
            q.push(i);
            ct[i]=time[i-1] ;
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(int j=0 ;j<adj[node].size();j++)
            {
                indeg[adj[node][j]]-- ;
                ct[adj[node][j]]=max(ct[adj[node][j]],ct[node]+time[adj[node][j]-1]) ;

                if(!indeg[adj[node][j]])
                q.push(adj[node][j]);


            }
        }
     int ans = 0;
    for (int i = 1; i <= n; i++)
    ans = max(ans, ct[i]);

     return ans;
    }
};