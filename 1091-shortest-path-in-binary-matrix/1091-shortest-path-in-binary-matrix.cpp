class Solution {
public:
   
   int r,c ;
   int row[8]= {-1,-1,-1,0,0,1,1,1};
   int col[8]= {-1,0,1,-1,1,-1,0,1} ;
   bool valid(int i ,int j)
   {
    return i>=0 && i<r && j>=0 && j<c ;
   }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         r=grid.size() ;
         c=grid[0].size() ;
        int count=0 ;

        queue<pair<int,int>>q ;
        if(grid[0][0] !=0 || grid[r-1][c-1] !=0 )
        return -1 ;

        q.push({0,0});
        grid[0][0]=1 ;
        count++ ;

        while(!q.empty())
        {
            int n=q.size() ;
            while(n--)
            {
                int ni=q.front().first ;
                int nj=q.front().second ;
                q.pop() ;

                if(ni==r-1 && nj==c-1)
                return count ;

                for(int k=0 ;k<8 ;k++)
                {
                    if(valid(ni+row[k],nj+col[k]) && grid[ni+row[k]][nj+col[k]]==0){
                        grid[ni+row[k]][nj+col[k]]=1 ;
                        q.push({ni+row[k],nj+col[k]}) ;
                    }
                }
            }
            count++ ;
        }


        return -1 ;
    }
};