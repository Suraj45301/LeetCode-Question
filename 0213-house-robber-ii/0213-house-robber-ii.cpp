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

       vector<int> dp1(n, -1);
       vector<int> dp2(n, -1);


      int first= maxisum(n-1 ,1,nums,dp1) ; 
      int second=maxisum(n-2,0,nums,dp2) ;

      return max(first,second) ;
    }
};