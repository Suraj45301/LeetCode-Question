class Solution {
public:

  int maxisum(int n ,int end,vector<int>&nums,vector<int>&dp)
  {
    if(n==end)
    return nums[end] ;

    if(n==end+1)
    return max(nums[end],nums[end+1]) ;

    if(dp[n] !=-1)
    return dp[n] ;

    return dp[n]=max(maxisum(n-2,end,nums,dp)+nums[n],maxisum(n-1,end,nums,dp));
  }
    int rob(vector<int>& nums) {
       int n=nums.size() ;

       if(n==1)
       return nums[0] ;

       if (n == 2)
        return max(nums[0], nums[1]);


       vector<int> dp1(n, -1);
       vector<int> dp2(n, -1);

       dp1[0]=nums[0] ;
       dp1[1]=max(nums[0],nums[1]) ;

       for(int i=2 ;i<n-1 ;i++)
       {
        dp1[i]=max(dp1[i-2]+nums[i],dp1[i-1]);
       }
      
        dp2[1]=nums[1] ;
        dp2[2]=max(nums[1],nums[2]);

        for(int i=3 ;i<n ;i++)
        {
            dp2[i]=max(dp2[i-2]+nums[i],dp2[i-1]) ;
        }

      return max(dp1[n-2],dp2[n-1]) ;
    }
};