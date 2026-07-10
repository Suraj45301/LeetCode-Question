class Solution {
public:
   
   int maxiamount(int n ,vector<int>&nums,vector<int>&dp)
   {
   
   if(n==0)
   return nums[0] ;

    if(n==1)
    return max(nums[0],nums[1]) ;

    if(dp[n] !=-1)
    return dp[n] ;

    return dp[n]=max(maxiamount(n-2,nums,dp)+nums[n],maxiamount(n-1,nums,dp)) ;
   }
    
    int rob(vector<int>& nums) {
       int n=nums.size() ;

       if(n==1)
       return nums[0];
       vector<int>dp(3,-1) ;
      dp[0]=nums[0] ;
      dp[1]=max(nums[1],nums[0]) ;
     

      for(int i=2 ;i<n ;i++)
      {
         dp[2] = max(dp[0] + nums[i], dp[1]);
        dp[0] = dp[1];
        dp[1] = dp[2];
      }
      return dp[1] ;
    }
};