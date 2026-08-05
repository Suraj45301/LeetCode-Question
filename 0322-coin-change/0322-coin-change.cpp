class Solution {
public:
 const int INF = 1e9;
    
    int coinChange(vector<int>& coins, int amount) {
       int n=coins.size() ;

       vector<int>dp(amount+1,1e9) ;
       dp[0]=0 ;

       for(int coin:coins)
       {
         for(int j=coin ;j<=amount ;j++)
         {
            dp[j] =min(dp[j],1+dp[j-coin]) ;
         }
       }
       return dp[amount]==1e9 ? -1:dp[amount] ;
    }
};