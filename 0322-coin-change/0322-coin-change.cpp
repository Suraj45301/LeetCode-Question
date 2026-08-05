class Solution {
public:
 const int INF = 1e9;
    int coin(int n ,vector<int>&coins ,int amount,vector<vector<int>>&dp) 
    {

       if (amount < 0)
         return INF;

        if (amount == 0)
         return 0;

       if (n == 0)
        return INF ;

        if(dp[n][amount] !=-1)
        return dp[n][amount] ;

     return dp[n][amount]=min(coin(n-1,coins,amount,dp),1+coin(n ,coins,amount-coins[n-1],dp)) ;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size() ;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1)) ;
       int ans= coin(n ,coins ,amount ,dp ) ;

        return (ans==INF)?-1:ans ;
    }
};