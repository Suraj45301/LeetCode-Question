class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0 ;
        int len=0 ;

        for(int n:nums)
        {
            if(n==0)
            {
                count=0 ;
                continue ;
            }
            count++ ;
            len=max(count,len) ;
        }
        return len;
    }
};