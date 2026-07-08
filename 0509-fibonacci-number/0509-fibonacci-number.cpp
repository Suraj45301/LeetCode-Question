class Solution {
public:

   
    int fib(int n) {
    
    if(n<=1)
    return n ;
     int first=0 ;
     int second=1 ;
     int ans=first+second ;

     for(int i=3 ;i<=n ;i++)
     {
        first=second;
        second=ans ;
        ans=first+second ;
     }
     return ans ;
    }
};