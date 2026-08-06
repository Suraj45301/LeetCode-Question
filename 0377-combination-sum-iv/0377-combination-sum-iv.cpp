class Solution {
public:

    int perfectsum(int n ,vector<int>&nums ,int target,vector<int>&dp)
    {
        if(target==0)
        return 1 ;

        if(target<0)
        return 0 ;

        if(dp[target] !=-1)
        return dp[target] ;

        int result=0 ;
        for(int j=0 ;j<n ;j++)
        {
            result +=perfectsum(n,nums ,target-nums[j],dp) ;
        }

        return dp[target]=result ;
    }
    int combinationSum4(vector<int>& nums, int target) {
      int n=nums.size() ;
      vector<int>dp(target+1,-1) ;
      return perfectsum(n,nums,target,dp) ;  
    }
};