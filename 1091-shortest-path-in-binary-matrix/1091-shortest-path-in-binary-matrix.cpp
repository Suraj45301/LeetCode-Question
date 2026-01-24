class Solution {
public:

    int r,c ;
    int row[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
     int col[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
     bool valid(int i ,int j)
     {
        return i>=0 && i<r && j>=0 && j<c ;
     }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        r=grid.size() ;
        c=grid[0].size() ;

        queue<pair<int,int>>q ;
        int count=0 ;
       
        if(grid[0][0] !=0 || grid[r-1][c-1] !=0)
        return -1 ;

        q.push({0,0}) ;
        grid[0][0]=1 ;
        count++ ;

        while(!q.empty()) 
        {
            int n=q.size() ;
            while(n--)
            {
            int new_i=q.front().first ;
            int new_j=q.front().second ;
            q.pop() ;

            if (new_i == r-1 && new_j == c-1)
            return count;

            for(int k=0 ;k<8 ;k++)
            {
                if(valid(new_i+row[k],new_j+col[k]) && grid[new_i+row[k]][new_j+col[k]]==0)
                {
                    grid[new_i+row[k]][new_j+col[k]]=1 ;
                    q.push({new_i+row[k],new_j+col[k]}) ;
                    
                }
            }
            }
            count++ ;
        }
        return -1 ;

    }
};