class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0 ;
        int end=0 ;
        int zerocount=0 ;
        int len=0 ;
        while(end<nums.size())
        {
            if(nums[end]==0)
            zerocount++ ;

            while(zerocount>k)
            {
                if(nums[start]==0)
                zerocount-- ;

                start++;
            }
            len=max(len,end-start+1) ;
            end++ ;
        }
        return len ;
    }
};