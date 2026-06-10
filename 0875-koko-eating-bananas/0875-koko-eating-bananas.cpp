class Solution {
public:

    bool check(vector<int>&piles ,int mid,int h)
    {
        long long ans=0 ;

        for(int i=0 ;i<piles.size() ;i++)
        {
            ans +=piles[i]/mid ;

            if(piles[i]%mid !=0)
            {
                ans++ ;
            }
        }
        return ans<=h ;
    }

 
    int minEatingSpeed(vector<int>& piles, int h) {
        
     int start=1 ;
     int end=0 ;
     int result=0 ;
     for(int i=0 ;i<piles.size() ;i++)
     {
        end =max(end,piles[i]) ;
     }
     while(start<=end)
     {
        int mid=start+(end-start)/2 ;

        if(check(piles,mid,h))
        {
            result=mid ;
            end=mid-1 ;
        }
        else{
            start=mid+1 ;
        }
     }
       return result ;
    }
};