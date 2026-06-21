class Solution {
public:
    int maxDistance(string moves) {
        int ans=0 ;
        int x=0 ,y=0 ,k=0;
       for(char c:moves)
       {
           if(c=='L')
               x-- ;

           else if(c=='R')
               x++ ;

            else if(c=='U')
               y++ ;

            else if(c=='D')
               y--;

           else
               k++ ;
           
       }
        return ans=abs(x)+abs(y)+k ;
    }
};