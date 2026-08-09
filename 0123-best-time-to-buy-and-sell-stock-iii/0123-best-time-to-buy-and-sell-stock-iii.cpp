class Solution {
public:

   int maximumProfit(int index ,int buy ,int trans ,int n ,vector<int>&prices, vector<vector<vector<int>>>&dp)
   {
   if(trans==0 || index==n)
   return 0 ;

   if(dp[index][buy][trans] != -1)
   return dp[index][buy][trans] ;

   if(buy==1)
   {
    return dp[index][buy][trans]=max(-prices[index]+maximumProfit(index+1 ,0 ,trans ,n ,prices,dp),maximumProfit(index+1 ,1 ,trans ,n ,prices,dp));
   }
   else{
   return dp[index][buy][trans]=max(prices[index]+maximumProfit(index+1 ,1 ,trans-1 ,n ,prices,dp),maximumProfit(index+1 ,0 ,trans ,n ,prices,dp)) ;
   }
   }


    int maxProfit(vector<int>& prices) {
        int n=prices.size() ;

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2 ,vector<int>(3,-1))) ;
        return maximumProfit(0 ,1,2,n,prices,dp) ;
    }
};