class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size() ;
        int total=0 ;
        for(int s:stones)
        total +=s ;

        vector<bool>dp(total+1/2 ,0) ;
        dp[0]=1 ;

        for(int i=0 ;i<n ;i++)
        {
            for(int j=total/2 ;j-stones[i]>=0 ;j--)
            dp[j]=dp[j] || dp[j-stones[i]] ;
        }

        int maxi=0 ;

        for(int i=total/2 ;i>=0 ;i--)
        {
            if(dp[i]==1)
            {
                maxi=i ;
                break ;
            }
        }

        return total-2*maxi ;
    }
};