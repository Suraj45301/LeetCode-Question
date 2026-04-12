class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long ans=0 ;
        long long start=0 ,end=0 ;
         int maxElement=INT_MIN ;
        long long  count=0 ,total=0;
        for(int i=0 ;i<nums.size() ;i++)
        maxElement=max(maxElement,nums[i]) ;

        while(end<nums.size())
        {
            if(nums[end]==maxElement) count++ ;

            while(count==k)
            {
                total +=nums.size()-end ;

                if(nums[start]==maxElement)count-- ;
                start++ ;
            }
            end++ ;
        }
      return total ;
    }
};