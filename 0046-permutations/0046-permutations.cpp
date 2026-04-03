class Solution {
public:
    
    void permutation(vector<vector<int>>&ans ,vector<int>&nums ,int index)
    {
        if(nums.size()==index)
        {
            ans.push_back(nums) ;
            return ;
        }
       for(int i=index ;i<nums.size() ;i++)
       {
        swap(nums[index],nums[i]) ;
        permutation(ans,nums,index+1) ;
        swap(nums[i],nums[index]) ;
       }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans ;
        permutation(ans,nums,0) ;
        return ans ;
    }
};