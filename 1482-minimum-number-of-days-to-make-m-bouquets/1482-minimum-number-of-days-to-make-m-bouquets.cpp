class Solution {
public:
   
     bool check(vector<int>&bloomDay ,int mid ,int m ,int k)
     {
        int flower=0 ;
        int bounquet=0 ;

        for(int bloom:bloomDay)
        {
            if(bloom<=mid)
            {
                flower++ ;

                if(flower==k)
                {
                    bounquet++ ;
                    flower=0 ;
                }
            }
            else{
                flower=0 ;
            }

        }
        return bounquet>=m ;
     }
  
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size() ;
        if(k>n/m)
        return -1 ;

        int start=INT_MAX,end=0,ans=0 ;
        for(int i=0 ;i<bloomDay.size() ;i++)
        {
            start=min(start ,bloomDay[i]);
            end=max(end,bloomDay[i]) ;
        }

        while(start<=end)
        {
           int mid=start+(end-start)/2 ;
            
            if(check(bloomDay ,mid,m,k))
            {
                ans=mid ;
                end=mid-1 ;
            }
            else{
                start=mid+1 ;
            }
        }

        
        return ans ;

    }
};