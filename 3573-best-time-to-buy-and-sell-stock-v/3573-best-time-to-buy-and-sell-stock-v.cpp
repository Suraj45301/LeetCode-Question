class Solution {
public:

    long long maxiProfit(int index ,int buy ,int n ,int k ,vector<int>&prices,vector<vector<vector<long long>>>&dp)
    {

        if(k==0)
        return 0 ;

        if(index==n)
        return buy==1 ?INT_MIN :0 ;

        if(dp[index][k][buy] !=-1)
        return dp[index][k][buy] ;

        if(buy==2)
        {
            return dp[index][k][buy]=max(maxiProfit(index+1 ,2,n,k,prices,dp),max(-prices[index]+maxiProfit(index+1,0 ,n,k,prices,dp),prices[index]+maxiProfit(index+1,1,n,k,prices,dp))) ;
        }
        else if(buy==1)
        {
            return dp[index][k][buy]=max(maxiProfit(index+1,1,n,k,prices,dp),-prices[index]+maxiProfit(index+1,2,n,k-1 ,prices,dp)) ;
        }
        else
        {
            return dp[index][k][buy]=max(maxiProfit(index+1,0 ,n,k,prices,dp),prices[index]+maxiProfit(index+1,2 ,n,k-1,prices,dp)) ;
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size() ;
         
         vector<vector<vector<long long>>>dp(n+1 ,vector<vector<long long>>(k+1,vector<long long>(3,-1))) ;
       return  maxiProfit(0 ,2 ,n ,k,prices,dp) ;
    }
};