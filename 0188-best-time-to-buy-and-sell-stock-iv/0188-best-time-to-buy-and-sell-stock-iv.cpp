class Solution {
public:
  int maxiProfit(int index ,int buy ,int k ,int n ,vector<int>&prices,  vector<vector<vector<int>>>&dp)
  {
    if(k==0 || index==n)
    return 0 ;

    if(dp[index][k][buy] != -1)
    return dp[index][k][buy] ;

    if(buy==1)
    {
        return dp[index][k][buy]=max(maxiProfit(index+1 ,1 ,k ,n,prices,dp),-prices[index]+maxiProfit(index+1,0,k,n,prices,dp)) ;
    }
    else
    {
        return dp[index][k][buy]=max(maxiProfit(index+1,0,k,n,prices,dp),prices[index]+maxiProfit(index+1,1,k-1,n,prices,dp)) ;
    }
  }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size() ;

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1))) ;
        return maxiProfit(0 ,1,k,n,prices,dp) ;
    }
};