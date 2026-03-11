class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k= 0;
        int j=nums.size()-1 ;
        for(int i=0 ;i<=j;i++)
        {
            if(nums[i]==0)
            {
                swap(nums[k],nums[i]);
                k++ ;
            }
            else if(nums[i]==2)
            {
                swap(nums[i],nums[j]);
                i-- ;
                j-- ;
            }

        }
    }
};