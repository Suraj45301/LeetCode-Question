class Solution {
public:

    int maxiProfit(int index ,int buy ,int n ,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(index >= n)
        return 0;


        if(dp[index][buy] !=-1)
        return dp[index][buy] ;

        if(buy==1)
        {
            return dp[index][buy]= max(-prices[index]+maxiProfit(index+1 ,0 ,n ,prices,dp),maxiProfit(index+1,1,n,prices,dp)) ;
        }
        else{
            return dp[index][buy]= max(prices[index]+maxiProfit(index+2 ,1 ,n,prices,dp),maxiProfit(index+1,0 ,n,prices,dp)) ;
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size() ;

        vector<vector<int>>dp(n+1,vector<int>(2,-1)) ;

        return maxiProfit(0 ,1 ,n,prices,dp) ;
    }
};