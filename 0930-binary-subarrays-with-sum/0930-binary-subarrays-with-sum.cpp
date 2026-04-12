class Solution {
public:

 int atmostgoal(vector<int>& nums, int goal)
 {

    if(goal<0)return 0 ;
    int start=0 ;
        int end=0 ;
        int sum=0 ;
        int total=0 ;
        while(end<nums.size())
        {
            sum +=nums[end] ;
            while(sum>goal)
            {
                sum -=nums[start] ;
                start++ ;
            }
            total +=end-start+1 ;
            end++ ;
        }
        return total ;
 }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atmostgoal(nums,goal)-atmostgoal(nums,goal-1) ;
    }
};