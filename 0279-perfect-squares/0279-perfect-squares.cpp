class Solution {
public:
    int numSquares(int n) {
        
        vector<int>nums ;
        for(int i=1 ;i*i<=n ;i++)
        nums.push_back(i*i) ;

        vector<int>dp(n+1,1e9) ;
        dp[0]=0 ;

        for(int num:nums)
        {
            for(int j=num ; j<=n ;j++)
            dp[j]=min(dp[j],1+dp[j-num]) ;
        }

        return dp[n]==1e9 ? -1:dp[n] ;
    }
};