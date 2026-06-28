class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>>merge ;
        sort(occupiedIntervals.begin() ,occupiedIntervals.end()) ;

        for(auto& it:occupiedIntervals)
        {
           if(merge.empty() || it[0]>merge.back()[1]+1 )
           {
            merge.push_back(it) ;
           }
           else{
            merge.back()[1]=max(merge.back()[1] ,it[1]) ;
           }
        }
        vector<vector<int>>ans ;
        for(auto& it:merge)
        {
            int l=it[0],r=it[1] ;

            if(r<freeStart || l> freeEnd)
            ans.push_back({l,r});

            else
            {
                if(l<freeStart)
                ans.push_back({l,freeStart-1});

                if(r>freeEnd)
                ans.push_back({freeEnd+1,r}) ;
            }
        }
        return ans ;
    }
};