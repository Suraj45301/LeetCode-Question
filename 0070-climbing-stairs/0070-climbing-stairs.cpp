class Solution {
public:

    
   
    int climbStairs(int n) {

    if(n<=1)
    return 1 ;

    int first=1 ;
    int second=1 ;
    int ans=first+second ;

    for(int i=3 ;i<=n ;i++)
    {
        first=second ;
        second=ans ;
        ans=first+second ;
    }

    return ans ;


        
    }
};