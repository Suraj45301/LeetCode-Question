class Solution {
public:

    int coinchange(int n ,int amount ,vector<int>&coins,vector<vector<int>>&dp)
    {
        
         if(amount==0)
        return 0 ;

          
        if(amount<0 || n<0)
        return 0 ;

        if(dp[n][amount] !=-1)
        return dp[n][amount] ;

        return dp[n][amount]=coinchange(n-1 ,amount ,coins,dp)+coinchange(n ,amount-coins[n-1] ,coins,dp) ;
    }
    int change(int amount, vector<int>& coins) {
        
      int n=coins.size() ;
      vector<unsigned long long>dp(amount+1,0) ;
      dp[0]=1 ;

      for(int i=0 ;i<n; i++)
      {
        for(int j=coins[i] ;j<=amount ;j++)
        {
            dp[j] +=dp[j-coins[i]] ;
        }
      }

        
      
        return dp[amount] ;

      
    }
};