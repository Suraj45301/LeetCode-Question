class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size() ;
       queue<int>q ;
       vector<bool>visited(n,0) ;
       int count=0 ;

       for(int i=0 ;i<n ;i++)
       {
        if(!visited[i])
        {
            q.push(i) ;
            count++ ;

        }

        while(!q.empty())
        {
            int node=q.front() ;
            q.pop() ;

            for(int j=0 ;j<isConnected[node].size() ;j++)
            {
                
                if(!visited[j] && isConnected[node][j]==1)
                {
                    visited[j]=1 ;
                    q.push(j) ;
                }
            }
        }
       }

  return count ;
    }
};