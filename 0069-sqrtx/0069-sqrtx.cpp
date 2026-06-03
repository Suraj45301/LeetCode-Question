class Solution {
public:
    int mySqrt(int x) {
        int start=0 ;
        int end=x ;
        int  target=x ;

        while(start<=end)
        {
            long long mid=start+(end-start)/2 ;
            
            if(mid*mid==target)
            return mid ;

            else if(mid*mid <target)
             start=mid+1 ;

            else
            end=mid-1 ;
        }
        return end ;
    }
};