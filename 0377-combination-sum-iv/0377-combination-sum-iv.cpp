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
      vector<long long>dp(target+1,-1) ;

      dp[0]=1 ;
       
       for(int i=1 ;i<=target ;i++)
       {
        int result=0 ;
        for(int j=0 ;j<n ;j++)
        {
            if(i-nums[j]>=0)
            result +=dp[i-nums[j]] ;
        }
        dp[i]=result ;
       }
       return dp[target] ;
    }
};