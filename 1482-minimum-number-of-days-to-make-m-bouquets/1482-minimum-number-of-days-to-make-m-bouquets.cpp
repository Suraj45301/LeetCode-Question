class Solution {
public:

   bool check(vector<int>& bloomDay ,int mid ,int m ,int k)
   {
    int flower=0 ;
    int bounquet=0 ;

    for(int i=0 ;i<bloomDay.size() ;i++)
    {
        if(bloomDay[i]<=mid)
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

      int start=0 ,end=0 ;
      int ans=0 ;
      for(int i=0 ;i<n ;i++)
      {
        end=max(bloomDay[i],end) ;
        start=min(bloomDay[i],start);
      }
      while(start<=end)
      {
        int mid=start+(end-start)/2 ;
        if(check(bloomDay,mid ,m,k))
        {
            ans=mid ;
            end=mid-1 ;
        }
        else{
            start=mid+1 ;
        }
      }  
      return ans;     

    }
};