class Solution {
public:

    int maxiProfit(int index ,int buy ,int n ,int fee ,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(index==n)
        return 0 ;
      
        if(dp[index][buy] !=-1)
        return dp[index][buy] ;

        if(buy==1)
        {
            return dp[index][buy]=max(-prices[index]+maxiProfit(index+1 ,0 ,n ,fee,prices,dp),maxiProfit(index+1,1,n,fee,prices,dp)) ;
        }
        else{
            return dp[index][buy]=max(prices[index]-fee+maxiProfit(index+1,1,n,fee,prices,dp),maxiProfit(index+1,0,n,fee,prices,dp)) ;
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size() ;

        vector<vector<int>>dp(n+1,vector<int>(2,-1)) ;
        return maxiProfit(0,1 ,n,fee,prices,dp) ;
    }
};