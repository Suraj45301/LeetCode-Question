class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0 ;
        int maxisum=INT_MIN ;
        for(int num:nums)
        {
            sum +=num;

            maxisum=max(maxisum,sum) ;
           if(sum<0)
            sum=0 ;
           
        }
        return maxisum ;
    }
};