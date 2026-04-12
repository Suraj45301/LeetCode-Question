class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1) return 0 ;
        int start=0 ;
        int end=0 ;
        int total=0 ;
        int product=1 ;
        while(end<nums.size())
        {
            product *=nums[end] ;
            while(product>=k)
            {
                product /=nums[start] ;
                start++ ;
            }
            total +=end-start+1 ;
            end++ ;
        }
        return total  ;

    }
};