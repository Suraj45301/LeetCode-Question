class Solution {
public:

    int mini(vector<int>&cost,int n ,vector<int>&dp)
    {
        if(n<=1) return 0 ;

        if(dp[n] != -1) return dp[n] ;

        return dp[n]=min(cost[n-1]+mini(cost,n-1,dp),cost[n-2]+mini(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size() ;
        vector<int>dp(n+1,-1) ;

        return mini(cost,n,dp) ;
        
    }
};