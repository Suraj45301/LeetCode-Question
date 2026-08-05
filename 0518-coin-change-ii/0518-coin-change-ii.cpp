class Solution {
public:

    int coinchange(int n ,int amount ,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(amount==0)
            return 1 ;

            else
            return 0 ;
        }
        if(amount<0 || n<0)
        return 0 ;

        if(dp[n][amount] !=-1)
        return dp[n][amount] ;

        return dp[n][amount]=coinchange(n-1 ,amount ,coins,dp)+coinchange(n ,amount-coins[n-1] ,coins,dp) ;
    }
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size() ;
        vector<vector<int>>dp(n+1 ,vector<int>(amount+1,-1));

        return coinchange(n ,amount ,coins ,dp) ;
    }
};